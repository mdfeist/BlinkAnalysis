#include "StdAfx.h"
#include "EyeCalibration.h"
#include "Dikablis.h"

#include "EyeCalibrationWizardFormController.h"

#include <osg/Matrix>

EyeCalibration::EyeCalibration(void) { 
	this->rbHeadId = -1; 
	this->rbViewingObjectId = -1; 
}

char* EyeCalibration::getNameById(int id) {
	if (id < 0)
		return 0;

	ClientHandler* client = AppData::getInstance()->getClient();

	if (client)
	{
		RigidBody* body = client->getRigidBody(id);
		if (body)
		{
			return body->getName();
		}
	}

	return 0;
}

bool EyeCalibration::addPoint() {

	ClientHandler* client = AppData::getInstance()->getClient();

	if (client == NULL)
		return false;
	
	RigidBody* head = client->getRigidBody(this->rbHeadId);
	RigidBody* viewing = client->getRigidBody(this->rbViewingObjectId);

	if (head == NULL || viewing == NULL)
		return false;

	osg::Matrixf headMatrix;
	headMatrix.makeIdentity();
	headMatrix.makeTranslate(head->getPosition());
	headMatrix.makeRotate(head->getRotation());

	if (!headMatrix.invert_4x4(headMatrix))
		return false;

	osg::Vec3 ray;
	ray = viewing->getPosition() - head->getPosition();
	ray = headMatrix * ray;
	ray.normalize();
	ray = ray/ray.z();

	Dikablis::journal_struct journal;
	journal = Dikablis::getJournal();

	CalibrationPoint point(journal.field_x, journal.field_y, ray);
	calibrationPoints.push_back(point);

	return true;
}

void EyeCalibration::calibrate() {
	EyeCalibrationWizardFormController::getInstance()->calibrationOutputLog("Starting Calibration\n");

	char buf[512];
	sprintf_s(buf, "A total of %d points was collected.\n", calibrationPoints.size());
	EyeCalibrationWizardFormController::getInstance()->calibrationOutputLog(buf);
}