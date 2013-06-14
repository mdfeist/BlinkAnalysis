// BlinkAnalysis.cpp : main project file.

#include "stdafx.h"
#include "MainForm.h"
#include "MainFormController.h"
#include "AppData.h"

using namespace BlinkAnalysis;
using namespace System::Runtime::InteropServices;

[STAThreadAttribute]
int main(array<System::String ^> ^args)
{
	// Enabling Windows XP visual effects before any controls are created
	Application::EnableVisualStyles();
	Application::SetCompatibleTextRenderingDefault(false); 

	// Create the MainForm using MainFormController
	MainForm^ mainForm = MainFormController::getInstance()->createForm();

	// Create the ClientHandler and attach it to the global App Data
	ClientHandler* client = new ClientHandler();
	AppData::getInstance()->setClient(client);

	// Create new custom world
	CaptureWorld* world = new CaptureWorld();
	world->setName("default");
	WorldManager::getInstance()->addWorld(world);
	//TODO TESTING
	world->addPlane(osg::Vec3(0, 0, 0.5), osg::Vec3(1, 0, 0.5), osg::Vec3(0, 1, 0.5), "Plane");

	if (args->Length >= 1) {
		char* fileName = (char*)Marshal::StringToHGlobalAnsi(args[0]).ToPointer();

		if (AppData::getInstance()->openFile(fileName))
			mainForm->setFormName(args[0]);
		else
			MessageBox::Show(gcnew String(AppData::getInstance()->getLastError()));

		Marshal::FreeHGlobal((IntPtr)fileName);
	}

	// Create the main window and run it
	Application::Run(mainForm);
	return 0;
}
