/**
 * Marker.h
 * Created By: Michael Feist
 */

#pragma once
// Holds the data for an OptiTrack Marker
class Marker {
public:
	int id;
	float x, y, z;
	float size;

	Marker() {
		this->id = 0;
		this->x = 0; 
		this->y = 0; 
		this->z = 0; 
		this->size = 0;}

	Marker(int id, float x, float y, float z, float size = 0) {
		this->id = id;
		this->x = x;
		this->y = y;
		this->z = z;
		this->size = size;
	}
};
