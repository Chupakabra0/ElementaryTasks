//
// Created by Александр Сафиюлин on 10.12.2020.
//

#pragma once

#ifndef FOURTHTASK_VIEW_VIEW_HPP_
#define FOURTHTASK_VIEW_VIEW_HPP_

#include "../Services/Errors/ErrorHandler/ErrorHandler.hpp"

namespace task::fourth {
template<class Ostream>
class View {
 public:
  View() = delete;

  View(const View &) = delete;

  View(View &&) = delete;

  explicit View(Ostream &out, task::helpers::ErrorHandler errorHandler)
	  : out_(out), errorHandler_(errorHandler) {}

  View &operator=(const View &) = delete;

  View &operator=(View &&) = delete;

  void OutMemoryError() {
	this->outError(task::helpers::ErrorCode::MEMORY_OUT);
  }

  void OutParseError() {
	this->outError(task::helpers::ErrorCode::MEMORY_OUT);
  }

  void OutArgsNotEnoughError() {
	this->outError(task::helpers::ErrorCode::NOT_ENOUGH_ARGS);
  }

  void OutDoneMessage() {
	this->out_ << "Done" << std::endl;
  }

  void OutNotDoneMessage() {
	this->out_ << "Not enough memory to do this operation" << std::endl;
  }

  void OutInstructionsMessage() {
	this->OutArgsNotEnoughError();
	this->out_ << "FourthTask.exe filePath stringToCount" << std::endl
			   << "FourthTask.exe filePath stringToFind stringToReplace" <<
			   std::endl;
  }

  void OutFileWordCount(const std::string &string, const unsigned count) {
	std::stringstream ss;
	switch (count) {
	  case 0u: {
		ss << "There's no \"" << string << "\" word in the file.\n";
		break;
	  }
	  case 1u: {
		ss << "There's just one\"" << string << "\" word in the file.\n";
		break;
	  }
	  default: {
		ss << "There's " << count << " \"" << string
		   << "\" words in the file\n";
		break;
	  }
	}

	this->out_ << ss.str();
  }

  ~View() = default;
 private:
  void outError(task::helpers::ErrorCode errorCode) {
	this->errorHandler_.SetErrorCode(errorCode);
	this->errorHandler_.OutError();
  }

  Ostream &out_;
  task::helpers::ErrorHandler errorHandler_;
};
}

#endif //FOURTHTASK_VIEW_VIEW_HPP_
