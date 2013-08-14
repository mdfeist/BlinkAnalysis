#include "stdafx.h"
#include "StreamSettingsForm.h"
#include "MainFormController.h"

namespace BlinkAnalysis {
	System::Void StreamSettingsForm::setMainFormSave() {
		MainFormController::getInstance()->setSave();
	}
}