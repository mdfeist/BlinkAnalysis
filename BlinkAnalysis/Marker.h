/**
 * Marker.h
 * Created By: Michael Feist
 */

#pragma once

#include <windows.h>

#include <osg/Vec3>
#include <osg/Vec4>

// Holds the data for an OptiTrack Marker
class Marker {
private:
	int id;
	osg::Vec3 position;
	float size;

	float radius;
	osg::Vec4 color;

	bool selected;

	DWORD lastUpdate;
public:
	Marker(int id = 0, float x = 0.f, float y = 0.f, float z = 0.f, float size = 0.f) {
		this->id = id;
		this->position = osg::Vec3(x, y, z);
		this->size = size;

		this->radius = 5.f;
		this->color = osg::Vec4(1.f, 1.f, 1.f, 1.f);

		this->selected = false;
	}

	void setID(int id) { this->id = id; }
	int getID() { return this->id; }

	void setPosition(osg::Vec3 position) { this->position = position; }
	osg::Vec3 getPosition() { return this->position; }
	float& x() { return this->position.x(); }
	float& y() { return this->position.y(); }
	float& z() { return this->position.z(); }

	void setRadius(float r) { this->radius = r; }
	float getRadius() { return this->radius; }

	void setColor(osg::Vec4 color) { this->color = color; }
	osg::Vec4 getColor() { return this->color; }

	void select() { this->selected = true; }
	void deselect() { this->selected = false; }
	bool isSelected() { return this->selected; }

	void setSize(float size) { this->size = size; }
	float getSize() { return this->size; }

	void update() { this->lastUpdate = GetTickCount(); }

	bool isUpdated() {
		DWORD current = GetTickCount();

		if (current - this->lastUpdate < 1000)
			return true;

		return false;
	}
};
