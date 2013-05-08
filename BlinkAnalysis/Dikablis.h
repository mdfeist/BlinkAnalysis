#pragma once
#include "stdafx.h"
#include <string>

namespace Dikablis {
	typedef struct
	{
		unsigned int index;		// image number
		unsigned int timestamp; // counts up in milliseconds
		int eyeroihoriz;		// Calibration setting 0-500
		int eyeroivert;			// Calibration setting 0-500
		int eyeroizoomx;		// Calibration setting 0-300
		int eyeroizoomy;		// Calibration setting 0-300
		bool olinecalib;		// OnLine Calibration
		bool eye_valid;			// True if pupil was detected
		int eye_x;				// Range 0 to 768 | Horizontal position of pupil in eye camera
		int eye_y;				// Range 0 to 576 | Vertical position of pupil in eye camera
		int field_x;			// Range 0 to 768 | Horizontal position of the focal point in field camera
		int field_y;			// Range 0 to 576 | Vertical position of the focal point in field camera
	} journal_struct;

	void setIPAddress(std::string ip);
	void setPort(std::string p);

	void startServer();
	void stopServer();

	void connectToDikablis(std::string ip, std::string p);
};