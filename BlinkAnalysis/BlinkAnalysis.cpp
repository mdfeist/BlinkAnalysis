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
	
	// Create the Main Form and attach it to MainFormController
	MainForm ^mainForm = gcnew MainForm();
	MainFormController::getInstance()->attachMainForm(mainForm);

	// Create the ClientHandler and attach it to the global App Data
	ClientHandler* client = new ClientHandler();
	AppData::getInstance()->setClient(client);

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
