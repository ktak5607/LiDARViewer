#include "stdafx.h"
#include "Point.h"

Point::Point() {};
Point::Point(double x1, double y1, double z1, unsigned short intensity1, char comboItems1, unsigned char classification1, unsigned char scanAngleRank1, 
			unsigned char userData1, unsigned short pointID1, double gpsTime1) {
	x = x1;
	y = y1;
	z = z1;
	intensity = intensity1;
}

Point::~Point() {
}

double Point::getX() {
	return x;
}

double Point::getY() {
	return y;
}

double Point::getZ() {
	return z;
}

unsigned short Point::getIntensity() {
	return intensity;
}

char Point::getComboItems() {
	return comboItems;
}

unsigned char Point::getClassification() {
	return classification;
}


unsigned char Point::getScanAngleRank() {
	return scanAngleRank;
}

unsigned char Point::getUserData() {
	return userData;
}
unsigned short Point::getPointID() {
	return pointID;
}

double Point::getGPSTime() {
	return gpsTime;
}