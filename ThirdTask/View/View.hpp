//
// Created by Александр Сафиюлин on 04.12.2020.
//

#pragma once

#ifndef THIRDTASK_VIEW_HPP
#define THIRDTASK_VIEW_HPP

#include <Triangle/Triangle.hpp>

namespace task::third {
template<class Ostream>
class View {
 public:
  View() = delete;

  View(const View &) = delete;

  View(View &&) = delete;

  View &operator=(const View &) = delete;

  View &operator=(View &&) = delete;

  explicit View(Ostream &out, const helpers::ErrorHandler errorHandler)
  : View(out, errorHandler, {}) {};

  explicit View(Ostream &out, const helpers::ErrorHandler errorHandler, const
  std::multiset<Triangle, std::greater<>>
  &multiset)
	  : out_(out), triangleMultiset_(multiset), errorHandler_(errorHandler) {}

  void OutTriangles() {
	for (const auto &i : this->triangleMultiset_) {
	  this->out_ << i << std::endl;
	}
  }

  void OutInstructions() const {
	this->out_ << "Enter a new triangle in format:" << std::endl
			   << "Name, FirstSide, SecondSide, ThirdSide" << std::endl;
  };

  void OutMemoryError() {
	this->outError(helpers::ErrorCode::MEMORY_OUT);
  }

  void OutParseError() {
	this->outError(helpers::ErrorCode::PARSE_FAILED);
  }

  void OutValidError() {
	this->outError(helpers::ErrorCode::VALIDATION_FAILED);
  }

  [[nodiscard]] std::multiset<Triangle,
							  std::greater<>> GetMultiset() const {
	return this->triangleMultiset_;
  }

  void SetMultiset(const std::multiset<Triangle, std::greater<>>
				   &multiset) {
	if (this->triangleMultiset_ == multiset) {
	  return;
	}
	this->triangleMultiset_ = multiset;
  }

  void AddToMultiset(const Triangle &triangle) {
	this->triangleMultiset_.insert(triangle);
  }

 private:
  void outError(const helpers::ErrorCode errorCode) {
	this->errorHandler_.SetErrorCode(errorCode);
	this->errorHandler_.OutError(std::string("\n"));
  }

  Ostream &out_;
  std::multiset<Triangle, std::greater<>> triangleMultiset_;
  helpers::ErrorHandler errorHandler_;
};

}

#endif //THIRDTASK_VIEW_HPP
