#pragma once
#include <windows.h>
#include <tchar.h>
#include <stdio.h>

#include <iostream>
#include <fstream>

#include <string.h>
#include <map>
#include <vector>

#include "RigidBody.h"
#include "Marker.h"

#include "pugixml.hpp"

class Recording
{
private:
	class Marker_Frame {
	private:
		int _id;
		float _x, _y, _z;
	public:
		Marker_Frame(int id) { 
			_id = id;

			_x = 0.f;
			_y = 0.f;
			_z = 0.f;
		}

		Marker_Frame(int id, 
			float x, float y, float z) { 
			_id = id;

			_x = x;
			_y = y;
			_z = z;
		}

		int getID() { return _id; }

		float& x() { return _x; }
		float& y() { return _y; }
		float& z() { return _z; }
	};

	class RB_Frame {
	private:
		int _id;
		float _x, _y, _z;
		float _qx, _qy, _qz, _qw;

		std::vector<Marker_Frame> markers;
	public:
		RB_Frame(int id) {
			_id = id;

			_x = 0.f;
			_y = 0.f;
			_z = 0.f;

			_qx = 0.f;
			_qy = 0.f;
			_qz = 0.f;
			_qw = 0.f;
		}

		RB_Frame(int id,
			float x, float y, float z,
			float qx, float qy, float qz, float qw) {
			_id = id;

			_x = x;
			_y = y;
			_z = z;

			_qx = qx;
			_qy = qy;
			_qz = qz;
			_qw = qw;
		}

		int getID() { return _id; }

		float& x() { return _x; }
		float& y() { return _y; }
		float& z() { return _z; }

		float& qx() { return _qx; }
		float& qy() { return _qy; }
		float& qz() { return _qz; }
		float& qw() { return _qw; }

		void addMarker(Marker_Frame marker) {
			this->markers.push_back(marker);
		}

		std::vector<Marker_Frame> getMarkers() { return this->markers; }
		int getNumberOfMarkers() { return this->markers.size(); }
	};

	class Frame {
	private:
		int _id;

		std::vector<RB_Frame> rigidBodies;
		std::vector<Marker_Frame> markers;
	};
	
	int id;
	std::string name;

	std::map<int, RigidBody*> rigidBodies;

	bool readyForRecording;
	std::vector<Frame> frames;

	void initializeRecording();

	std::ofstream tempFileStream;

	TCHAR szTempFileName[MAX_PATH];  
    TCHAR lpTempPathBuffer[MAX_PATH];
public:
	Recording(void);
	~Recording(void);

	void setName(std::string name) { this->name = name; }
	std::string getName() { return this->name; }

	void closeRecording();
	void addFrame();
	int numberOfFrames() { return this->frames.size(); }

	bool loadRecording(pugi::xml_node recording);
};

