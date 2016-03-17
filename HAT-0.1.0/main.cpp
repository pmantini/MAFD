/*
* File:   main.cpp
* Author: sagar
*
* Created on 10 September, 2012, 7:48 PM
*/
#include "HATHeader.h"
#include "CameraInstance.h"
#include "DisplayCamera.h"
#include "FrameRate.h"

using namespace cv;
using namespace std;

int main() {
	
	CameraInstance cameraTest;
	if (cameraTest.setStream(0)){
		cout << "Camera initialized" << endl;
	}
	else{
		cout << "cannot open camera";
	}

	DisplayCamera test(&cameraTest);
	
	FrameRate frameRate(&cameraTest);
	getchar();

	return 0;
}