//
// Created by Александр Сафиюлин on 12.12.2020.
//

#pragma once

#ifndef EIGHTHTASK_VIEW_VIEW_HPP_
#define EIGHTHTASK_VIEW_VIEW_HPP_

#include <vector>

#include <Errors/ErrorHandler/ErrorHandler.hpp>

namespace task::eighth {
template<class Ostream>
class View {
 public:
//------------------------- CTORS ----------------------------------------------

  View() = delete;

  View(const View &) = delete;

  View(View &&) noexcept = delete;

  View &operator=(const View &) = delete;

  View &operator=(View &&) noexcept = delete;

  explicit View(Ostream &out, const helpers::ErrorHandler errorHandler)
	  : View(out, errorHandler, {}) {}

  explicit View(Ostream &out, const helpers::ErrorHandler errorHandler,
				const std::vector<unsigned long long> &numbers)
	  : numbers_(numbers), out_(out), errorHandler_(errorHandler) {}

//--------------------------- OUTPUT -------------------------------------------

  void OutMemoryError() {
	this->outError(helpers::ErrorCode::MEMORY_OUT);
  }

  void OutParseError() {
	this->outError(helpers::ErrorCode::PARSE_FAILED);
  }

  void OutNotEnoughArgsMessage() {
	this->outError(helpers::ErrorCode::NOT_ENOUGH_ARGS);
	this->out_ << "EighthTask.exe lowLimit highLimit" << std::endl;
  }

  void OutNumbers(const std::string &delimiter = std::string(" ")) {
	for (const auto &i : this->numbers_) {
	  this->out_ << i << delimiter;
	}
  }

//------------------------- GETTERS/SETTERS ------------------------------------

  [[nodiscard]] std::vector<unsigned long long> GetNumbers() const {
	return this->numbers_;
  }

  void SetNumbers(const std::vector<unsigned long long> &numbers) {
	if (this->numbers_ == numbers) {
	  return;
	}
	this->numbers_ = numbers;
  }

//------------------------ CALL PUSH BACK --------------------------------------

  void PushToNumbers(const unsigned long long number) {
	this->numbers_.push_back(number);
  }

//------------------------ DTOR ------------------------------------------------

  ~View() = default;
 private:
  void outError(const helpers::ErrorCode errorCode) {
	this->errorHandler_.SetErrorCode(errorCode);
	this->errorHandler_.OutError("\n");
  }

  std::vector<unsigned long long> numbers_;
  Ostream &out_;
  helpers::ErrorHandler errorHandler_;
};
}

#endif //EIGHTHTASK_VIEW_VIEW_HPP_