//
// Created by Александр Сафиюлин on 09.12.2020.
//
#include <iostream>

#include "Envelope.hpp"

task::second::Envelope::Envelope(double heightAndWidth) : Envelope(
	heightAndWidth,
	heightAndWidth) {}

task::second::Envelope::Envelope(double height, double width)
	: height_(height), width_(width) {}

double task::second::Envelope::GetHeight() const {
  return this->height_;
}
void task::second::Envelope::SetHeight(unsigned int height) {
  if (std::abs(this->height_ - height) <
	  std::numeric_limits<double>::epsilon()) {
	return;
  }
  this->height_ = height;
}
double task::second::Envelope::GetWidth() const {
  return this->width_;
}
void task::second::Envelope::SetWidth(unsigned int width) {
  if (std::abs(this->width_ - width) <
	  std::numeric_limits<double>::epsilon()) {
	return;
  }
  this->width_ = width;
}