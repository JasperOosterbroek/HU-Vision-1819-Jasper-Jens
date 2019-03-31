#include "StudentPreProcessing.h"


IntensityImage * StudentPreProcessing::stepToIntensityImage(const RGBImage &image) const {
	/* Method 1:  implementatie RGB devide by three
	// Get width and height
	const int imgWidth = image.getWidth();
	const int imgHeight = image.getHeight();

	// Create new intensity image
	IntensityImage * intImage = ImageFactory::newIntensityImage(imgWidth, imgHeight);

	// Set width & height intensity image
	intImage->set(imgWidth, imgHeight);

	// Loop through supplied rgb image
	for (int width = 0; width < imgWidth; width++) {
		for (int height = 0; height < imgHeight; height++) {
			// Get current pixel
			RGB pixel = image.getPixel(width, height);
			// create new intensity pixel
			Intensity newIntensity = static_cast<char>((pixel.r + pixel.g + pixel.b) / 3);
			// set intensity pixel on correct position in new intensity image
			intImage->setPixel(width, height, newIntensity);
		}
	}
	return intImage;
	*/
	
	/* Method 2:  implementatie RGB weighted */

	// Weights as seen in implementation document
	double RWeight = 0.2126;
	double GWeight = 0.7152;
	double BWeight = 0.0722;

	// Check if weights are propely set
	if (RWeight + GWeight + BWeight > 1){
		return nullptr;
	}

	// Get width and height 
	const int imgWidth = image.getWidth();
	const int imgHeight = image.getHeight();
	
	// Create new intensity image
	IntensityImage * intImage = ImageFactory::newIntensityImage(imgWidth, imgHeight);

	// Set width & height intensity image
	intImage->set(imgWidth, imgHeight);

	// Loop through supplied rgb image
	for (int width = 0; width < imgWidth; width++){
		for (int height = 0; height < imgHeight; height++){
			// Get current pixel
			RGB pixel = image.getPixel(width, height);
			// create new intensity pixel
			Intensity newIntensity = static_cast<char>(((pixel.r * RWeight) + (pixel.g * GWeight) + (pixel.b * BWeight)));
			// set intensity pixel on correct position in new intensity image
			intImage->setPixel(width, height, newIntensity);
		}
	}
	return intImage;

}

IntensityImage * StudentPreProcessing::stepScaleImage(const IntensityImage &image) const {
	return nullptr;
}

IntensityImage * StudentPreProcessing::stepEdgeDetection(const IntensityImage &image) const {
	return nullptr;
}

IntensityImage * StudentPreProcessing::stepThresholding(const IntensityImage &image) const {
	return nullptr;
}