#pragma once
#include<vector>
#include "stdafx.h"

using namespace std;
class Header
{
public:
	vector<unsigned char> fileData;
	unsigned short sourceID;
	unsigned short globalEncoding;
	unsigned long projID1;
	unsigned short projID2;
	unsigned short projID3;
	vector <unsigned char> projID4;
	unsigned char majorVersion;
	unsigned char minorVersion;
	vector <char> sysIdentifier;
	vector <char> genSoft;
	unsigned short dayCreated;
	unsigned short yearCreated;
	unsigned short headerSize;
	//832 bytes to coordinates start
	unsigned long offsetToPointData;
	unsigned long numVarLenRec;
	unsigned char pntFormat;
	unsigned short pntDataLen;
	unsigned long numOfPnts;
	unsigned long numOfPntsRet[5];
	double xScaleFactor;
	double yScaleFactor;
	double zScaleFactor;
	double xOffset;
	double yOffset;
	double zOffset;
	Header();
	~Header();
};

