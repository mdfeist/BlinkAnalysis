/**
 * ClientHandler.cpp
 * Created By: Michael Feist
 */
#include "StdAfx.h"
#include "ClientHandler.h"

#include <string.h>

#include <iostream>
#include <fstream>
#include <windows.h>
 
using namespace std;

// Dikablis
int ClientHandler::DikablisViewingWidth = 768;
int ClientHandler::DikablisViewingHeight = 576;

int ClientHandler::DikablisViewingMargin = 100;

int ClientHandler::DikablisViewingSize = 3 * ((DikablisViewingWidth + 2*DikablisViewingMargin) * (DikablisViewingHeight + 2*DikablisViewingMargin));

// Constructor: Sets the default values for the ClientHandler
ClientHandler::ClientHandler(void)
{ 
	this->client = 0;
	this->natNetServerRunning = false;
	
	this->iOptiTrackConnectionType = ConnectionType_Multicast;
	
	this->iOptiTrackServerCommandPort = 1510;
	this->iOptiTrackServerDataPort = 1511;

	this->setLocalIpAddress("127.0.0.1");
	this->setOptiTrackServerIpAddress("127.0.0.1");
	
	this->g_hMutex = CreateMutex(
		NULL,
		//(LPSECURITY_ATTRIBUTES)SYNCHRONIZE, 
		FALSE, 
		NULL);

	this->rigidBodyTool = -1;

	this->dikablisEyeVectorArray = (float*) malloc(sizeof(float) * ClientHandler::DikablisViewingSize);
}

// Cleans up the ClientHandler
ClientHandler::~ClientHandler(void)
{
	// Free the mutex
	CloseHandle(this->g_hMutex);

	if (this->dikablisEyeVectorArray != NULL)
		free(this->dikablisEyeVectorArray);
}

void ClientHandler::setRay(osg::Vec3 ray, int x, int y) {
	if (this->dikablisEyeVectorArray != NULL) {
		int i = x + DikablisViewingMargin;
		int j = y + DikablisViewingMargin;

		int loc = (j*DikablisViewingWidth*2*DikablisViewingMargin) + i;
		loc *= 3;
		if (loc >= 0 && loc < DikablisViewingSize - 3) {
			this->dikablisEyeVectorArray[loc + 0] = ray.x();
			this->dikablisEyeVectorArray[loc + 1] = ray.y();
			this->dikablisEyeVectorArray[loc + 2] = ray.z();
		}
	}
}

osg::Vec3 ClientHandler::getRay(int x, int y) {
	osg::Vec3 ray;

	if (this->dikablisEyeVectorArray != NULL) {
		int i = x + DikablisViewingMargin;
		int j = y + DikablisViewingMargin;

		int loc = (3*j*DikablisViewingWidth*2*DikablisViewingMargin) + i;

		ray.x() = this->dikablisEyeVectorArray[loc + 0];
		ray.y() = this->dikablisEyeVectorArray[loc + 1];
		ray.z() = this->dikablisEyeVectorArray[loc + 2];
	}

	return ray;
}

void ClientHandler::save() {
	int width = 512;
	int height = 512;

    HANDLE file;
    BITMAPFILEHEADER fileHeader;
    BITMAPINFOHEADER fileInfo;
    RGBTRIPLE *image;
    DWORD write = 0;
    image = new RGBTRIPLE[width*height*24];
 
    file = CreateFile(L"C:\\Users\\mdfeist\\Desktop\\rayMap.bmp",GENERIC_WRITE,0,NULL,CREATE_ALWAYS,FILE_ATTRIBUTE_NORMAL,NULL);  //Sets up the new bmp to be written to
 
    fileHeader.bfType = 19778;                                                                    //Sets our type to BM or bmp
    fileHeader.bfSize = sizeof(fileHeader.bfOffBits) + sizeof(RGBTRIPLE);                                                //Sets the size equal to the size of the header struct
    fileHeader.bfReserved1 = 0;                                                                    //sets the reserves to 0
    fileHeader.bfReserved2 = 0;
    fileHeader.bfOffBits = sizeof(BITMAPFILEHEADER)+sizeof(BITMAPINFOHEADER);                    //Sets offbits equal to the size of file and info header
 
    fileInfo.biSize = sizeof(BITMAPINFOHEADER);
    fileInfo.biWidth = width;
    fileInfo.biHeight = height;
    fileInfo.biPlanes = 1;
    fileInfo.biBitCount = 24;
    fileInfo.biCompression = BI_RGB;
    fileInfo.biSizeImage = width * height * (24/8);
    fileInfo.biXPelsPerMeter = 2400;
    fileInfo.biYPelsPerMeter = 2400;
    fileInfo.biClrImportant = 0;
    fileInfo.biClrUsed = 0;
 
    WriteFile(file,&fileHeader,sizeof(fileHeader),&write,NULL);
    WriteFile(file,&fileInfo,sizeof(fileInfo),&write,NULL);
 
    for (int i = 0; i < width*height*24; i++)
    {
		int index = i / 24;

		if (index >= 0 && index < DikablisViewingSize - 3) {
			int b = 10*(this->dikablisEyeVectorArray[3*index + 0] + 20);
			int g = 10*(this->dikablisEyeVectorArray[3*index + 1] + 20);
			int r = 10*(this->dikablisEyeVectorArray[3*index + 2] + 20);


			image[i].rgbtBlue = b;
			image[i].rgbtGreen = g;
			image[i].rgbtRed = r;
		} else {
			image[i].rgbtBlue = 255;
			image[i].rgbtGreen = 255;
			image[i].rgbtRed = 255;
		}
    }
 
    WriteFile(file, image, fileInfo.biSizeImage, &write, NULL);
 
    CloseHandle(file);
}


// Add a Rigid Body to the ClientHandler
bool ClientHandler::addRigidBody(int id, RigidBody* rigidBody)
{
	// Try to insert the Rigid Body
	std::pair<std::map<int,RigidBody*>::iterator,bool> ret;
	ret = this->rigidBodies.insert ( std::pair<int, RigidBody*>(id, rigidBody) );

	// Check if insertion was successful
	if (ret.second == false)
		return false;

	// If insertion was successful return true
	return true;
}

// Get Rigid Body based on ID
RigidBody* ClientHandler::getRigidBody(int id)
{
	// Try to find the Rigid Body
	std::map<int, RigidBody*>::iterator ret;
	ret = this->rigidBodies.find(id);

	// If not found return NULL
	if ( ret == this->rigidBodies.end())
		return 0;

	// If found return the Rigid Body
	return ret->second;
}

// Update the Position and Orientation of a Rigid Body based on it's Id
void ClientHandler::transformRigidBody(int id, osg::Vec3 pos, osg::Vec4 rot)
{
	// Find the Rigid Body based on its Id
	std::map<int, RigidBody*>::iterator ret;
	ret = this->rigidBodies.find(id);

	// If Rigid Body was not found return
	if ( ret == this->rigidBodies.end())
		return;

	// If the Rigid Body was found update its Position and Orientation
	ret->second->addFrame(pos, rot);
}

// Return the map of all the Rigid Bodies
std::map<int, RigidBody*>* ClientHandler::getRigidBodyMap()
{
	return &this->rigidBodies;
}

bool ClientHandler::addLabeledMarker(int id, Marker* marker)
{
	std::pair<labeledmarker_iterator, bool> ret;
	ret = labeledMarkers.insert(std::pair<int, Marker*>(id, marker));

	return (ret.second == false) ? false : true;
}

Marker* ClientHandler::getLabeledMarker(int id)
{
	labeledmarker_iterator itr = labeledMarkers.find(id);

	return (itr == labeledMarkers.end()) ? NULL : itr->second;
}

std::map<int, Marker*>* ClientHandler::getLabeledMarkerMap()
{
	return &labeledMarkers;
}

void ClientHandler::clearLabeledMarkers()
{
	for (labeledmarker_iterator itr = labeledMarkers.begin(); itr != labeledMarkers.end(); itr++)
	{
		delete itr->second;
	}

	labeledMarkers.clear();
}

void ClientHandler::clearStaleMarkers()
{
	for (labeledmarker_iterator itr = labeledMarkers.begin(); itr != labeledMarkers.end();)
	{
		if (!itr->second->isUpdated())
		{
			delete itr->second;
			labeledMarkers.erase(itr++);
		}
		else
		{
			++itr;
		}
	}
}

