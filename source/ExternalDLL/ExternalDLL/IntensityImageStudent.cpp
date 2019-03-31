#include "IntensityImageStudent.h"
#include <iostream>

IntensityImageStudent::IntensityImageStudent() : IntensityImage() {}

IntensityImageStudent::IntensityImageStudent(const IntensityImageStudent &other) : IntensityImage(other.getWidth(), other.getHeight()) {
	this->arrPicture = new Intensity[other.getWidth() * other.getHeight()];
	for (int i = 0; i < ( other.getWidth() * other.getHeight() ); i++) {
		this->arrPicture[i] = other.getPixel(i);
	}
}

IntensityImageStudent::IntensityImageStudent(const int width, const int height) : IntensityImage(width, height) {
	if (width >= 0 && height >= 0) {
		this->arrPicture = new Intensity[width * height];
	}
}

IntensityImageStudent::~IntensityImageStudent() {
	delete[] this->arrPicture;
}

void IntensityImageStudent::set(const int width, const int height) {
	IntensityImage::set(width, height);
	delete[] this->arrPicture;
	this->arrPicture = new Intensity[width * height];
}

void IntensityImageStudent::set(const IntensityImageStudent &other) {
	if (other.getWidth() >= 0 && other.getHeight() >= 0) {
		IntensityImage::set(other.getWidth(), other.getHeight());
		delete[] this->arrPicture;
		this->arrPicture = new Intensity[other.getWidth(), other.getHeight()];
		for (int i = 0; i < (other.getWidth() * other.getHeight()); i++) {
			this->arrPicture[i] = other.getPixel(i);
		}
	}
}

void IntensityImageStudent::setPixel(int x, int y, Intensity pixel) {
	if (x >= 0 && y >= 0) {
		this->setPixel(x + (y * this->getWidth()), pixel);
	}
}

void IntensityImageStudent::setPixel(int i, Intensity pixel) {
	if (i >= 0 && i < this->getWidth() * this->getHeight()) {
		this->arrPicture[i] = pixel;
	}
}

Intensity IntensityImageStudent::getPixel(int x, int y) const {
	if (x >= 0 && y >= 0) {
		return this->arrPicture[x + (y * this->getWidth())];
	}
	return 0;
}

Intensity IntensityImageStudent::getPixel(int i) const {
	if (i >= 0) {
		return this->arrPicture[i];
	}
	return 0;
}