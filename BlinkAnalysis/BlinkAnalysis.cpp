// BlinkAnalysis.cpp : main project file.

#include "stdafx.h"
#include "MainForm.h"
#include "MainFormController.h"
#include "AppData.h"

using namespace BlinkAnalysis;

[STAThreadAttribute]
int main(array<System::String ^> ^args)
{
	// Enabling Windows XP visual effects before any controls are created
	Application::EnableVisualStyles();
	Application::SetCompatibleTextRenderingDefault(false); 
	
	// Create the Main Form and attach it to MainFormController
	MainForm ^mainForm = gcnew MainForm();
	MainFormController::getInstance()->attachMainForm(mainForm);

	// Create the ClientHandler and attach it to the global App Data
	ClientHandler* client = new ClientHandler();
	AppData::getInstance()->setClient(client);

	// Create the main window and run it
	Application::Run(mainForm);
	return 0;
}
