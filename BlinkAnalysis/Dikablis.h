 /**
 * Dikablis.h
 * Created By: Michael Feist
 *
 * Handles the eye tracking from the Dikablis Recorder.
 */
#pragma once
#include "stdafx.h"
#include <string>

namespace Dikablis {

	// Structure to hold the journal information from
	// Dikablis Recorder.
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
		int eye_w;				// Number		  | Width of the pupil in pixels
		int eye_h;				// Number		  | Height of the pupil in pixels
		int eye_a;				// Number		  | Area of the pupil in pixels
		int field_x;			// Range 0 to 768 | Horizontal position of the focal point in field camera
		int field_y;			// Range 0 to 576 | Vertical position of the focal point in field camera
	} journal_struct;

	journal_struct getJournal();

	// Set the Ip Address of the machine running Dikablis Recorder
	void setIPAddress(std::string ip);
	// Set the slave port of the machine running Dikablis Recorder
	void setPort(std::string p);

	// Start the connection with Dikablis Recorder
	void startServer();
	// Stop the connection with Dikablis Recorder
	void stopServer();

	// Create and start the connection with Dikablis Recorder
	void connectToDikablis(std::string ip, std::string p);
};