#pragma once
#include "stdafx.h"
#include <string>

#include "Dikablis.h"
#include "MainForm.h"

using namespace System;

public ref class MainFormController sealed
{
public:
	static MainFormController^ getInstance() {
		if(!m_pInstance) m_pInstance = gcnew MainFormController();
		return m_pInstance;
	}

	void dikablisOutputLog(std::string msg);
	void dikablisMessage(Dikablis::journal_struct journal);

	void optiTrackOutputLog(std::string msg);

	void attachMainForm(BlinkAnalysis::MainForm ^form) { this->mainForm = form; }
	void optiTrackUpdateData() { this->mainForm->optiTrackUpdateData(); }
	void optiTrackInitDataView() { this->mainForm->optiTrackInitDataView(); }
protected:
	MainFormController();
	~MainFormController();
private:
	static MainFormController^ volatile m_pInstance;

	BlinkAnalysis::MainForm ^mainForm;
};

