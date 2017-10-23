#pragma once
class Point
{
private:
	double x;
	double y;
	double z;
	unsigned short intensity;
	char comboItems;
	unsigned char classification;
	unsigned char scanAngleRank;
	unsigned char userData;
	unsigned short pointID;
	double gpsTime;
public:
	Point();
	Point(double x1, double y1, double z1, unsigned short intensity1, char comboItems1, unsigned char classification1, unsigned char scanAngleRank1, unsigned char userData1, unsigned short pointID1, double gpsTime1);
	~Point();
	double getX();
	double getY();
	double getZ();
	unsigned short getIntensity();
	char getComboItems();
	unsigned char getClassification();
	unsigned char getScanAngleRank();
	unsigned char getUserData();
	unsigned short getPointID();
	double getGPSTime();
};

