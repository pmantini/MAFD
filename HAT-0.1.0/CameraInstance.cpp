#include "CameraInstance.h"

//Constructors
CameraInstance::CameraInstance(){

}

CameraInstance::CameraInstance(int CameraId){
	CameraStream.open(CameraId);
}

//set and get stream methods
bool CameraInstance::setStream(int cameraId){
	//Precondition test
	return CameraStream.open(cameraId);
}

cv::VideoCapture CameraInstance::getStream(){
	return CameraStream;
}

CameraInstance::~CameraInstance(){
	CameraStream.release();
}

