#ifndef CAMERA_INSTANCE_H
#define CAMERA_INSTANCE_H

#include "HATHeader.h"

class CameraInstance{	
	cv::VideoCapture CameraStream;

public:	
	CameraInstance();
	CameraInstance(int);	
	bool setStream(int);
	cv::VideoCapture getStream();		
	~CameraInstance();
};

#endif // CAMERA_INSTANCE_H
