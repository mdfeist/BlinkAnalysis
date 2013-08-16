#pragma once

#include <osg/Vec3>

/**
 * Contains helper functions for forms \n
 * Note: DO NOT pass in form control objects to modify,
 * as invoke may be required
 */
namespace FormUtils
{
	// extracts ID from text format "Name (##)"
	int worldExtractID(System::String^ str);

	// converts a managed String^ to unmanaged std::string*
	const char* managedStringToChar(System::String^ str);

	// set text to display when there is position data
	System::String^ setPoint(osg::Vec3* pos);

	// checks if input string is a valid float
	bool isFloat(System::String^ str);
	bool isPositiveFloat(System::String^ str);
	bool isPositiveNumber(System::String^ str);
};
