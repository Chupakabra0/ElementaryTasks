//
// Created by Александр Сафиюлин on 30.11.2020.
//

#pragma once

#include <sstream>
#include <string>

#include "../Services/Errors/ErrorHandler/ErrorHandler.hpp"

#ifndef SECONDTASK_VIEW_HPP
#define SECONDTASK_VIEW_HPP

namespace task::second {
template<class Ostream>
class View {
 public:
  View() = delete;

  View(const View &) = default;

  View(View &&) noexcept = default;

  explicit View(Ostream &out, task::helpers::ErrorHandler errorHandler)
	  : out_(out), errorHandler_(errorHandler) {}

  explicit View(Ostream &out, const Envelope firstEnvelope, const Envelope
  secondEnvelope, task::helpers::ErrorHandler errorHandler)
	  : out_(out),
		firstEnvelope_(std::make_unique<Envelope>(firstEnvelope)),
		secondEnvelope_(std::make_unique<Envelope>(secondEnvelope)),
		errorHandler_(errorHandler) {}

  View &operator=(const View &) = default;

  View &operator=(View &&) noexcept = default;

  task::second::Envelope GetFirstEnvelope() const {
	return this->firstEnvelope_;
  }

  void SetFirstEnvelope(const task::second::Envelope &envelope) {
	this->firstEnvelope_ = std::make_unique<Envelope>(envelope);
  }

  task::second::Envelope GetSecondEnvelope() const {
	return this->secondEnvelope_;
  }

  void SetSecondEnvelope(const task::second::Envelope &envelope) {
	this->secondEnvelope_ = std::make_unique<Envelope>(envelope);
  }

  void OutMemoryError() {
	this->outError(task::helpers::ErrorCode::MEMORY_OUT);
  }

  void OutPutInResult() {
	std::stringstream ss;
	ss << "First envelope " << this->firstEnvelope_->GetHeight()
	   << " x " << this->firstEnvelope_->GetWidth() << " ";

	if (CanPutIn(*this->firstEnvelope_,
				 *this->secondEnvelope_)) {
	  ss << "can be put in second envelope";
	} else {
	  ss << "can NOT be put in second envelope";
	}

	ss << " " << this->secondEnvelope_->GetHeight() << " x "
	   << this->secondEnvelope_->GetWidth() << std::endl;

	ss << "Second envelope "
	   << this->secondEnvelope_->GetHeight() << " x "
	   << this->secondEnvelope_->GetWidth() << " ";
	if (CanPutIn(*this->secondEnvelope_,
				 *this->firstEnvelope_)) {
	  ss << "can be put in first envelope";
	} else {
	  ss << "can NOT be put in first envelope";
	}
	ss << " " << this->firstEnvelope_->GetHeight() << " x "
	   << this->secondEnvelope_->GetWidth() << std::endl;

	this->out_ << ss.str();
  }

  ~View() = default;

 private:
  void outError(task::helpers::ErrorCode errorCode) {
	this->errorHandler_.SetErrorCode(errorCode);
	this->errorHandler_.OutError();
  }

  std::unique_ptr<Envelope> firstEnvelope_;
  std::unique_ptr<Envelope> secondEnvelope_;
  Ostream &out_;
  task::helpers::ErrorHandler errorHandler_;
};

}

#endif //SECONDTASK_VIEW_HPP
