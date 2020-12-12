//
// Created by Александр Сафиюлин on 05.12.2020.
//

#pragma once

#ifndef FOURTHTASK_VIEW_HPP
#define FOURTHTASK_VIEW_HPP

#include <iostream>

#include "../Services/Errors/ErrorHandler/ErrorHandler.hpp"

namespace task::fifth {
template<class Ostream>
class View {
 public:
  View() = delete;

  View(const View &) = delete;

  View(View &&) noexcept = delete;

  View &operator=(const View &) = delete;

  View &operator=(View &&) noexcept = delete;

  explicit View(Ostream &out, const helpers::ErrorHandler errorHandler)
	  : number_(nullptr), numberString_(nullptr),
		out_(out), errorHandler_(errorHandler) {}

  explicit View(Ostream &out, const helpers::ErrorHandler errorHandler,
				std::unique_ptr<long long> &number,
				std::unique_ptr<std::string> &numberString)
	  : number_(std::move(number)), numberString_(std::move(numberString)),
		out_(out), errorHandler_(errorHandler) {}

  void OutDigitAndLetter() {
	if (nullptr == this->number_ || nullptr == this->numberString_) {
	  this->outError(helpers::ErrorCode::NOT_ENOUGH_ARGS);
	  return;
	}
	this->out_ << "Digit: " << *this->number_ << std::endl
			   << "Letter: " << *this->numberString_ << std::endl;
  }

  void OutNotEnoughArgsMessage() {
	this->outError(helpers::ErrorCode::NOT_ENOUGH_ARGS);
	this->out_ << "Args not enough" << std::endl
			   << "FifthTask.exe number" << std::endl;
  }

  [[nodiscard]] long long GetDigit() const {
	return *this->number_;
  }

  void SetDigit(long long number) {
	this->number_ = std::make_unique<long long>(number);
  }

  [[nodiscard]] std::string GetStr() const {
	return *this->number_;
  }

  void SetStr(const std::string &string) {
	this->numberString_ = std::make_unique<std::string>(string);
  }

  void OutMemoryError() {
	this->outError(helpers::ErrorCode::MEMORY_OUT);
  }

  void OutParseError() {
	this->outError(helpers::ErrorCode::PARSE_FAILED);
  }

  ~View() = default;

 private:
  void outError(const helpers::ErrorCode errorCode) {
	this->errorHandler_.SetErrorCode(errorCode);
	this->errorHandler_.OutError("\n");
  }

  std::unique_ptr<long long> number_;
  std::unique_ptr<std::string> numberString_;
  Ostream &out_;
  helpers::ErrorHandler errorHandler_;
};
}

#endif //FOURTHTASK_VIEW_HPP