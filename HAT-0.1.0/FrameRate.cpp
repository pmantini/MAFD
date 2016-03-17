#include "FrameRate.h"

FrameRate::FrameRate(){
	
}

FrameRate::FrameRate(CameraInstance* inputCameraInstance){
	cameraInstance = inputCameraInstance;	
	calculate();
		
}

void FrameRate::setCameraInstance(CameraInstance* inputCameraInstance){
	//Pre-condition check
	cameraInstance = inputCameraInstance;
}

void FrameRate::setFramesToCapture(int inputFramesToCapture){
	//Pre-condition check
	framesToCapture = inputFramesToCapture;
}

double FrameRate::calculate(){
	cv::VideoCapture streamToCalculate = cameraInstance->getStream();

	std::cout << "Reading " << framesToCapture << " Frames." << std::endl;	

	//Start and End capture time
	time_t start, end;

	cv::Mat tempFrameStore;

	time(&start);

	for (int i = 0; i < framesToCapture; i++){
		
		if (streamToCalculate.grab())streamToCalculate.retrieve(tempFrameStore);
		else std::cout << "Failed to grab!" << std::endl;
	}

	time(&end);

	// Time elapsed
	double seconds = difftime(end, start);
	std::cout << "Time taken : " << seconds << " seconds" << std::endl;
	
	// Calculate frames per second
	fps = framesToCapture / seconds;
	std::cout << "Estimated frames per second : " << fps << std::endl;

	return fps;

}