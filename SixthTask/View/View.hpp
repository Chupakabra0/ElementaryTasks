//
// Created by Александр Сафиюлин on 11.12.2020.
//

#include <Errors/ErrorHandler/ErrorHandler.hpp>
#include <LuckyTicketCounter/LuckyTicketCounter.hpp>

#pragma once

#ifndef SIXTHTASK_VIEW_VIEW_HPP_
#define SIXTHTASK_VIEW_VIEW_HPP_

namespace task::sixth {
template<class Ostream>
class View {
 public:
  View() = delete;

  View(const View &) = delete;

  View(View &&) noexcept = delete;

  View &operator=(const View &) = delete;

  View &operator=(View &&) noexcept = delete;

  explicit View(Ostream &out, task::helpers::ErrorHandler errorHandler)
	  : out_(out),
		errorHandler_(errorHandler),
		counter_(nullptr),
		luckyTicketType_(task::sixth::LuckyTicketType::NONE) {}

  explicit View(Ostream &out, task::helpers::ErrorHandler errorHandler,
				std::unique_ptr<unsigned long long> &counter,
				task::sixth::LuckyTicketType luckyTicketType =
				task::sixth::LuckyTicketType::NONE)
	  : out_(out), errorHandler_(errorHandler),
		counter_(std::move(counter)), luckyTicketType_(luckyTicketType) {}

  void OutCounter() {
	if (nullptr == this->counter_) {
	  this->outError(task::helpers::ErrorCode::NOT_ENOUGH_ARGS);
	  return;
	}
	this->out_ << "There are " << *this->counter_ << " lucky " <<
			   ToString(this->luckyTicketType_) << " tickets" << std::endl;
  }

  void OutNotEnoughArgumentsMessage() {
	this->out_ << "Not enough args" << std::endl
			   << "SixthTask.exe filePath" << std::endl;
  }

  void OutMemoryError() {
	this->outError(task::helpers::ErrorCode::MEMORY_OUT);
  }

  void OutParseError() {
	this->outError(task::helpers::ErrorCode::PARSE_FAILED);
  }

  void OutPathError() {
	this->outError(task::helpers::ErrorCode::FILE_NOT_EXIST);
  }

  void SetCounter(const unsigned long long counter) {
	this->counter_ = std::make_unique<unsigned long long>(counter);
  }

  [[nodiscard]] unsigned long long GetCounter() const {
	return *this->counter_;
  }

  void SetTicketType(task::sixth::LuckyTicketType type) {
	if (this->luckyTicketType_ == type) {
	  return;
	}
	this->luckyTicketType_ = type;
  }

  [[nodiscard]] task::sixth::LuckyTicketType GetTicketType() const {
	return this->luckyTicketType_;
  }

  ~View() = default;
 private:
  void outError(task::helpers::ErrorCode errorCode) {
	this->errorHandler_.SetErrorCode(errorCode);
	this->errorHandler_.OutError("\n");
  }

  std::unique_ptr<unsigned long long> counter_;
  task::sixth::LuckyTicketType luckyTicketType_;
  Ostream &out_;
  task::helpers::ErrorHandler errorHandler_;
};
}

#endif //SIXTHTASK_VIEW_VIEW_HPP_
