//
// Created by Александр Сафиюлин on 09.12.2020.
//

#include "Shape.hpp"

task::third::Shape::Shape(const std::string &name) : name_(name) {}

std::string task::third::Shape::GetName() const {
  return this->name_;
}

void task::third::Shape::SetName(const std::string &string) {
  if (this->name_ == string) {
	return;
  }
  this->name_ = string;
}