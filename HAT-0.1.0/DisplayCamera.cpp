#include "DisplayCamera.h"

DisplayCamera::DisplayCamera(){

}

DisplayCamera::DisplayCamera(CameraInstance* inputCameraInstance){
	cameraInstance = inputCameraInstance;
	display();
}

void DisplayCamera::setCameraInstance(CameraInstance* inputCameraInstance){
	//Pre-condition check
	cameraInstance = inputCameraInstance;	
}

bool DisplayCamera::display(){
	cv::VideoCapture streamToDisplay = cameraInstance->getStream();   //0 is the id of video device.0 if you have only one camera.

	if (!streamToDisplay.isOpened()) { //check if video device has been initialised
		std::cout << "DisplayCamera: display: cannot open camera";
	}

	//unconditional loop
	while (true) {
		cv::Mat cameraFrame;
		streamToDisplay.read(cameraFrame);
		cv::imshow("HAT Camera Display", cameraFrame);
		if (cv::waitKey(30) >= 0)			
			break;
	}

	streamToDisplay.release();
	return 1;
}

bool DisplayCamera::display(char* windowName){
	cv::VideoCapture streamToDisplay = cameraInstance->getStream();   //0 is the id of video device.0 if you have only one camera.

	if (!streamToDisplay.isOpened()) { //check if video device has been initialised
		std::cout << "DisplayCamera: display: cannot open camera";
	}

	//unconditional loop
	while (true) {
		cv::Mat cameraFrame;
		streamToDisplay.read(cameraFrame);
		cv::imshow(windowName, cameraFrame);
		if (cv::waitKey(30) >= 0)
			break;
	}

	return 1;
}

