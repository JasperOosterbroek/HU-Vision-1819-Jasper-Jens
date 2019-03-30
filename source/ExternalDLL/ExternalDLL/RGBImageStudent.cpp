#include "RGBImageStudent.h"
#include <iostream>

RGBImageStudent::RGBImageStudent() : RGBImage() {
}

RGBImageStudent::RGBImageStudent(const RGBImageStudent &other) : RGBImage(other.getWidth(), other.getHeight()) {
	this->arrPicture = new RGB[other.getWidth() * other.getHeight()];
	for (int i = 0; i < (other.getWidth() * other.getHeight()); i++) {
		this->arrPicture[i] = other.getPixel(i);
	}
}


RGBImageStudent::RGBImageStudent(const int width, const int height) : RGBImage(width, height){
	this->arrPicture = new RGB[width * height];
}

RGBImageStudent::~RGBImageStudent() {
	delete[] this->arrPicture;
}

void RGBImageStudent::set(const int width, const int height) {
	RGBImage::set(width, height);
	delete[] this->arrPicture;
	this->arrPicture = new RGB[width * height];
}

void RGBImageStudent::set(const RGBImageStudent &other) {
	RGBImage::set(other.getWidth(), other.getHeight());;
	this->set(other.getWidth(), other.getHeight());
}

void RGBImageStudent::setPixel(int x, int y, RGB pixel) {
	this->setPixel(x + (y * this->getWidth()), pixel);
}

void RGBImageStudent::setPixel(int i, RGB pixel) {
	if (i < this->getWidth() * this->getHeight()) {
		this->arrPicture[i] = pixel;
	}
}

RGB RGBImageStudent::getPixel(int x, int y) const {
	return this->getPixel(x + (y * this->getWidth()));
}

RGB RGBImageStudent::getPixel(int i) const {
	return this->arrPicture[i];
}