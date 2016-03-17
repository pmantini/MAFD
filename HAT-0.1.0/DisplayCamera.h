#ifndef DISPLAY_CAMERA_H
#define DISPLAY_CAMERA_H

#include "HATHeader.h"
#include "CameraInstance.h"

class DisplayCamera{		
	CameraInstance* cameraInstance;
	
public:
	DisplayCamera();
	DisplayCamera(CameraInstance*);
	void setCameraInstance(CameraInstance*);
	bool display();
	bool display(char*);	
};

#endif DISPLAY_CAMERA_H