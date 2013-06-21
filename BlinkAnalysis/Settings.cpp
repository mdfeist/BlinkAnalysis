#include "StdAfx.h"
#include "Settings.h"

#include "MainFormController.h"

Settings* Settings::m_pInstance = NULL; 

Settings::Settings(void)
{
	sprintf_s(this->error, "No Error");
	this->defaultProjectDirectory = "";
	loadSettings();
}


Settings::~Settings(void)
{
}

bool Settings::loadSettings() {
	pugi::xml_document doc;
	pugi::xml_parse_result result = doc.load_file("Settings/Settings.xml");

	if (result.status) {
		sprintf_s(this->error, "Load Setting Result: %s.", result.description());
		return false;
	} else {

		// Get Settings
		pugi::xml_node settings = doc.child("Settings");

		if (settings) {

			pugi::xml_node defaultProjectDirectory_node = settings.child("DefaultProjectDirectory");

			if (defaultProjectDirectory_node) {

				pugi::xml_attribute defaultProjectDirectory_path = defaultProjectDirectory_node.attribute("path");

				if (defaultProjectDirectory_path) {
					defaultProjectDirectory = defaultProjectDirectory_path.value();
					std::string myDocumentsKey("[MyDocuments]");
			
					/* Locate the substring to replace. */
					int index = defaultProjectDirectory.find(myDocumentsKey);
					if (index != std::string::npos) {
						/* Make the replacement. */
						std::string myDocuments = MainFormController::getInstance()->getSpecialFolderMyDocuments();
						defaultProjectDirectory.replace(index, myDocumentsKey.length(), myDocuments);
					}
				}  else {
					sprintf_s(this->error, "Can not find the path attribute for DefaultProjectDirectory node.");
					return false;
				}
			} else {
				sprintf_s(this->error, "Can not find DefaultProjectDirectory node.");
				return false;
			}
		} else {
			sprintf_s(this->error, "Can not find Settings node.");
			return false;
		}
	}

	return true;
}