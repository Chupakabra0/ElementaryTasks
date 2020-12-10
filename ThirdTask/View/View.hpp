//
// Created by Александр Сафиюлин on 04.12.2020.
//

#pragma once

#ifndef THIRDTASK_VIEW_HPP
#define THIRDTASK_VIEW_HPP

#include "../Models/Triangle/Triangle.hpp"

namespace task::third {
template<class Ostream>
class View {
 public:
  View() = delete;

  View(const View &) = delete;

  View(View &&) = delete;

  View &operator=(const View &) = delete;

  View &operator=(View &&) = delete;

  explicit View(Ostream &out, task::helpers::ErrorHandler errorHandler)
  : View(out, errorHandler, {}) {};

  explicit View(Ostream &out, task::helpers::ErrorHandler errorHandler, const
  std::multiset<Triangle, std::greater<>>
  &multiset)
	  : out_(out), triangleMultiset_(multiset), errorHandler_(errorHandler) {}

  void OutTriangles() {
	for (const auto &i : this->triangleMultiset_) {
	  this->out_ << i << std::endl;
	}
  }

  void OutInstructions() {
	this->out_ << "Enter a new triangle in format:" << std::endl
			   << "Name, FirstSide, SecondSide, ThirdSide" << std::endl;
  };

  void OutMemoryError() {
	this->OutError(task::helpers::ErrorCode::MEMORY_OUT);
  }

  void OutParseError() {
	this->OutError(task::helpers::ErrorCode::PARSE_FAILED);
  }

  void OutValidError() {
	this->OutError(task::helpers::ErrorCode::VALIDATION_FAILED);
  }

  [[nodiscard]] std::multiset<task::third::Triangle,
							  std::greater<>> GetMultiset() const {
	return this->triangleMultiset_;
  }

  void SetMultiset(const std::multiset<task::third::Triangle, std::greater<>>
				   &multiset) {
	if (this->triangleMultiset_ == multiset) {
	  return;
	}
	this->triangleMultiset_ = multiset;
  }

  void AddToMultiset(const task::third::Triangle &triangle) {
	this->triangleMultiset_.insert(triangle);
  }

 private:
  void OutError(task::helpers::ErrorCode errorCode) {
	this->errorHandler_.SetErrorCode(errorCode);
	this->errorHandler_.OutError(std::string("\n"));
  }

  Ostream &out_;
  std::multiset<task::third::Triangle, std::greater<>> triangleMultiset_;
  task::helpers::ErrorHandler errorHandler_;
};

}

#endif //THIRDTASK_VIEW_HPP
