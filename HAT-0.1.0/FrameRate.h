#ifndef FRAME_RATE_H
#define FRAME_RATE_H

#include "HATHeader.h"
#include "CameraInstance.h"

class FrameRate{
	int framesToCapture = 120;
	CameraInstance* cameraInstance;

public:
	double fps;
	FrameRate();
	FrameRate(CameraInstance*);
	FrameRate(CameraInstance*, int);
	void setCameraInstance(CameraInstance*);
	void setFramesToCapture(int);
	double calculate();
	
};

#endif FRAME_RATE_H