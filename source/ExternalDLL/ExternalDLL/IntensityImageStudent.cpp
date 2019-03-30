#include "IntensityImageStudent.h"
#include <iostream>

IntensityImageStudent::IntensityImageStudent() : IntensityImage() {
	this->arrPicture = new Intensity[0];
}

IntensityImageStudent::IntensityImageStudent(const IntensityImageStudent &other) : IntensityImage(other.getWidth(), other.getHeight()) {
	this->arrPicture = new Intensity[other.getWidth() * other.getHeight()];
	for (int i = 0; i < ( other.getWidth() * other.getHeight() ); i++) {
		this->arrPicture[i] = other.getPixel(i);
	}
}

IntensityImageStudent::IntensityImageStudent(const int width, const int height) : IntensityImage(width, height) {
	this->arrPicture = new Intensity[width * height];
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
	IntensityImage::set(other.getWidth(), other.getHeight());
	this->set(other.getWidth(), other.getHeight());
}

void IntensityImageStudent::setPixel(int x, int y, Intensity pixel) {
	this->setPixel(x + (y * this->getWidth()), pixel);
}

void IntensityImageStudent::setPixel(int i, Intensity pixel) {
	if (i < this->getWidth() * this->getHeight()) {
		this->arrPicture[i] = pixel;
	}
}

Intensity IntensityImageStudent::getPixel(int x, int y) const {
	return this->getPixel(x + (y * this->getWidth()));
}

Intensity IntensityImageStudent::getPixel(int i) const {
	return this->arrPicture[i];
}