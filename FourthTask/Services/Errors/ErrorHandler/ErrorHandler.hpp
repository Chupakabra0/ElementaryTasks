//
// Created by Александр Сафиюлин on 09.12.2020.
//

#pragma once

#ifndef FIRSTTASK_ERRORHANDLER_HPP
#define FIRSTTASK_ERRORHANDLER_HPP

#include "../ErrorCode/ErrorCode.hpp"

namespace task::helpers {
class ErrorHandler {
 public:
  ErrorHandler() = delete;

  ErrorHandler(const ErrorHandler &) = default;

  ErrorHandler(ErrorHandler &&) noexcept = default;

  explicit ErrorHandler(const ErrorCode error) : error_(error) {}

  ErrorHandler &operator=(const ErrorHandler &) = default;

  ErrorHandler &operator=(ErrorHandler &&) noexcept = default;

  [[nodiscard]] ErrorCode GetErrorCode() const {
	return this->error_;
  }

  void SetErrorCode(const ErrorCode error) {
    if (this->error_ == error) {
	  return;
    }
	this->error_ = error;
  }

  void OutError(const std::string &delimiter = "") const {
	std::cerr << ToString(error_) << delimiter;
  }

  ~ErrorHandler() = default;

 private:
  ErrorCode error_;
};
}

#endif //FIRSTTASK_ERRORHANDLER_HPP
