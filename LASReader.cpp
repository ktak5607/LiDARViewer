// OpenCVTest.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include<fstream>
#include<string>
#include<vector>
#include "Point.h"
#include "Header.h"

using namespace std;


void ReadPoints10(ifstream &f, Header* head) {

}
void ReadPoints11(ifstream &f, unsigned long* offsetToPointData, unsigned long* numOfPnts, double* xScaleFactor, double * yScaleFactor, double* zScaleFactor, double* xOffset, double* yOffset, double* zOffset) {

}

void ReadPoints12(ifstream &f, unsigned long* offsetToPointData, unsigned long* numOfPnts, double* xScaleFactor, double * yScaleFactor, double* zScaleFactor, double* xOffset, double* yOffset, double* zOffset) {
	f.seekg((int)offsetToPointData, ios_base::beg);
	vector<Point> points(*numOfPnts);
	for (int i = 0; i < *numOfPnts; i++) {  //check for conversion from long to int
		long xBase = 0;
		long yBase = 0;
		long zBase = 0;
		unsigned short intensity = 0;
		char comboItems = 'a';
		unsigned char classification = 'a';
		unsigned char scanAngleRank = 'a';
		unsigned char userData = 'a';
		unsigned short pointID = 0;
		double gpsTime = 0.0;
		f.read(reinterpret_cast<char*>(&xBase), sizeof(xBase));
		double x = (xBase * *xScaleFactor) + *xOffset;
		f.read(reinterpret_cast<char*>(&yBase), sizeof(yBase));
		double y = (yBase * *yScaleFactor) + *yOffset;
		f.read(reinterpret_cast<char*>(&zBase), sizeof(zBase));
		double z = (zBase * *zScaleFactor) + *zOffset;

		f.read(reinterpret_cast<char*>(&intensity), sizeof(intensity));
		f.read(reinterpret_cast<char*>(&comboItems), sizeof(comboItems));
		f.read(reinterpret_cast<char*>(&classification), sizeof(classification));
		f.read(reinterpret_cast<char*>(&scanAngleRank), sizeof(scanAngleRank));
		f.read(reinterpret_cast<char*>(&userData), sizeof(userData));
		f.read(reinterpret_cast<char*>(&pointID), sizeof(pointID));
		f.read(reinterpret_cast<char*>(&gpsTime), sizeof(gpsTime));
		points[i] = Point(x, y, z, intensity, comboItems, classification, scanAngleRank, userData, pointID, gpsTime);
	}
	cout << points[0].getX() << "," << points[0].getY() << "," << points[0].getZ() << endl;
}

void ReadPoints13(ifstream &f, unsigned long* offsetToPointData, unsigned long* numOfPnts, double* xScaleFactor, double * yScaleFactor, double* zScaleFactor, double* xOffset, double* yOffset, double* zOffset){
	f.seekg((int)offsetToPointData, ios_base::beg);
	vector<Point> points(*numOfPnts);
	for (int i = 0; i < *numOfPnts; i++) {  //check for conversion from long to int
		long xBase = 0;
		long yBase = 0;
		long zBase = 0;
		unsigned short intensity = 0;
		char comboItems = 'a';
		unsigned char classification = 'a';
		unsigned char scanAngleRank = 'a';
		unsigned char userData = 'a';
		unsigned short pointID = 0;
		double gpsTime = 0.0;
		f.read(reinterpret_cast<char*>(&xBase), sizeof(xBase));
		double x = (xBase * *xScaleFactor) + *xOffset;
		f.read(reinterpret_cast<char*>(&yBase), sizeof(yBase));
		double y = (yBase * *yScaleFactor) + *yOffset;
		f.read(reinterpret_cast<char*>(&zBase), sizeof(zBase));
		double z = (zBase * *zScaleFactor) + *zOffset;

		f.read(reinterpret_cast<char*>(&intensity), sizeof(intensity));
		f.read(reinterpret_cast<char*>(&comboItems), sizeof(comboItems));
		f.read(reinterpret_cast<char*>(&classification), sizeof(classification));
		f.read(reinterpret_cast<char*>(&scanAngleRank), sizeof(scanAngleRank));
		f.read(reinterpret_cast<char*>(&userData), sizeof(userData));
		f.read(reinterpret_cast<char*>(&pointID), sizeof(pointID));
		f.read(reinterpret_cast<char*>(&gpsTime), sizeof(gpsTime));
		points[i] = Point(x, y, z, intensity, comboItems, classification, scanAngleRank, userData, pointID, gpsTime);
	}
}


void ReadPoints14(ifstream &f, unsigned long* offsetToPointData, unsigned long* numOfPnts, double* xScaleFactor, double * yScaleFactor, double* zScaleFactor, double* xOffset, double* yOffset, double* zOffset) {

}
void ReadHeader(ifstream &f) {
	Header head;
	
	f.read((char*)&head.fileData[0], 4);
	
	f.read(reinterpret_cast<char*>(&head.sourceID), sizeof(head.sourceID));
	
	f.read(reinterpret_cast<char*>(&head.globalEncoding), sizeof(head.globalEncoding));
	
	f.read(reinterpret_cast<char*>(&head.projID1), sizeof(head.projID1));

	f.read(reinterpret_cast<char*>(&head.projID2), sizeof(head.projID2));

	f.read(reinterpret_cast<char*>(&head.projID3), sizeof(head.projID3));

	f.read((char*)&head.projID4[0], 8);

	f.read((char*)&head.majorVersion, 1);

	f.read((char*)&head.minorVersion, 1);
	
	f.read((char*)&head.sysIdentifier[0], 32);

	f.read((char*)&head.genSoft[0], 32);

	f.read(reinterpret_cast<char*>(&head.dayCreated), sizeof(head.dayCreated));

	f.read(reinterpret_cast<char*>(&head.yearCreated), sizeof(head.yearCreated));

	f.read(reinterpret_cast<char*>(&head.headerSize), sizeof(head.headerSize));

	//832 bytes to coordinates start
	f.read(reinterpret_cast<char*>(&head.offsetToPointData), sizeof(head.offsetToPointData));

	f.read(reinterpret_cast<char*>(&head.numVarLenRec), sizeof(head.numVarLenRec));

	f.read((char*)&head.pntFormat, 1);

	f.read(reinterpret_cast<char*>(&head.pntDataLen), sizeof(head.pntDataLen));

	f.read(reinterpret_cast<char*>(&head.numOfPnts), sizeof(head.numOfPnts));

	f.read(reinterpret_cast<char*>(&head.numOfPntsRet), sizeof(head.numOfPntsRet));

	f.read(reinterpret_cast<char*>(&head.xScaleFactor), sizeof(head.xScaleFactor));
	
	f.read(reinterpret_cast<char*>(&head.yScaleFactor), sizeof(head.yScaleFactor));
	
	f.read(reinterpret_cast<char*>(&head.zScaleFactor), sizeof(head.zScaleFactor));

	f.read(reinterpret_cast<char*>(&head.xOffset), sizeof(head.xOffset));
	
	f.read(reinterpret_cast<char*>(&head.yOffset), sizeof(head.yOffset));

	f.read(reinterpret_cast<char*>(&head.zOffset), sizeof(head.zOffset));
	if (head.minorVersion == 0) {
		ReadPoints10(f, &head);
	}
	else if(head.minorVersion == 1){
		ReadPoints11(f, &head);
	}
	else if (minorVersion == 2) {
		ReadPoints12(f, &offsetToPointData, &numOfPnts, &xScaleFactor, &yScaleFactor, &zScaleFactor, &xOffset, &yOffset, &zOffset);
	}
	else if (minorVersion == 3) {
		ReadPoints13(f, &offsetToPointData, &numOfPnts, &xScaleFactor, &yScaleFactor, &zScaleFactor, &xOffset, &yOffset, &zOffset);
	}
	else if (minorVersion == 4) {
		ReadPoints14(f, &offsetToPointData, &numOfPnts, &xScaleFactor, &yScaleFactor, &zScaleFactor, &xOffset, &yOffset, &zOffset);
	}

	else {
		cout << "Error: Could not properly identify las format version." << endl;
	}
}

int main()
{
	ifstream f;
	f.open("C:\\Users\\kevin.takala\\Documents\\Projects\\110901LiDAR\\ARRA-VA_11County_2010_001140.las", ios::in | std::ios::binary);
	f.unsetf(std::ios::skipws);
	ReadHeader(f);
	/*std::streampos fileSize;
	f.seekg(0, std::ios::end);
	fileSize = f.tellg();
	f.seekg(0, std::ios::beg);*/
	
	
	
	//cout << fileData[24] << endl;
	/*
	int temp;
	f.read(test, 4);
	cout << test[0] << test[1] << test[2] << test[3]<<endl;
	f.read(test, 2);
	unsigned short sourceID = (test[4] << 8) | test[5];
	cout << sourceID << endl;
	f.read(test, 2);
	unsigned short globalEncoding = (test[6] << 8) | test[7];
	cout << globalEncoding << endl;*/
	
	/*for (int i = 482; i < 487; i++) {

		if (i>= 0 && i < 4) {
			cout << test[i] << endl;
		}
		else if (i == 4 ) {
			char tchar[2];
			tchar[0] = test[i];
			tchar[1] = test[i + 1];
			temp = atoi(tchar);
			cout << "File Source ID is " << temp << endl;
			i = 5;
		}
		else if (i == 6) {
			char tchar[2];
			tchar[0] = test[i];
			tchar[1] = test[i + 1];
			temp = atoi(tchar);
			cout << "Global Encoding is " << temp << endl;
			i = 7;
		}
		else if (i == 8) {
			char projID1[4];
			char projID2[2];
			char projID3[2];
			char projID4[8];
			projID1[0] = test[i];
			projID1[1] = test[i + 1];
			projID1[2] = test[i + 2];
			projID1[3] = test[i + 3];
			unsigned long projID1L = atol(projID1);

			projID2[0] = test[i + 4];
			projID2[1] = test[i + 5];
			unsigned int projID2S = atoi(projID2);

			projID3[0] = test[i + 6];
			projID3[1] = test[i + 7];
			unsigned int projID3S = atoi(projID3);

			projID4[0] = test[i + 8];
			projID4[1] = test[i + 9];
			projID4[2] = test[i + 10];
			projID4[3] = test[i + 11];
			projID4[4] = test[i + 12];
			projID4[5] = test[i + 13];
			projID4[6] = test[i + 14];
			projID4[7] = test[i + 15];
			string projID4Str = projID4;
			cout << "Project ID data 1 is " << projID1L << endl;
			cout << "Project ID data 2 is " << projID2S << endl;
			cout << "Project ID data 3 is " << projID3S << endl;
			cout << "Project ID data 4 is " << projID4Str << endl;
			i = 23;
		}
		else if (i = 24) {
			unsigned char t = test[i];
			char t1 = t;
			int s = atoi(&t1);
			cout << "major version is: " << s << endl;
			i = 428;
		}
		
	}*/
	
	/*string sig = line;
	cout << sig << endl;
	cout << line << endl;
	f.read(line, 2);
	int source = atoi(line);
	cout << source << endl;

	f.read(line, 2);
	int glblEnc = atoi(line);
	cout << glblEnc << endl;*/

	//int i = 0;
	/*while (getline(f, line)) {
	cout << line<<endl;
	if (i > 5) {
	break;
	}
	i += 1;
	}*/
	string hold;
	std::cin >> hold;

	return 0;
}

