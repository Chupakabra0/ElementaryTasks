#pragma once

#ifndef FIRSTTASK_ERRORHANDLER_HPP
#define FIRSTTASK_ERRORHANDLER_HPP

#include <Errors/ErrorCode/ErrorCode.hpp>

namespace task::helpers {
// Error handler class
class ErrorHandler {
 public:
//-------------------------------- CTOR ----------------------------------------
  ErrorHandler() = delete;

  ErrorHandler(const ErrorHandler &) = default;

  ErrorHandler(ErrorHandler &&) noexcept = default;

  explicit ErrorHandler(const ErrorCode error) : error_(error) {}

  ErrorHandler &operator=(const ErrorHandler &) = default;

  ErrorHandler &operator=(ErrorHandler &&) noexcept = default;

//--------------------------- GETTERS/SETTERS ----------------------------------

  [[nodiscard]] ErrorCode GetErrorCode() const {
	return this->error_;
  }

  void SetErrorCode(const ErrorCode error) {
    if (this->error_ == error) {
	  return;
    }
	this->error_ = error;
  }

//---------------------- OUT ERROR ---------------------------------------------

  void OutError(const std::string &delimiter = "") const {
	std::cerr << ToString(error_) << delimiter;
  }

//---------------------------------- DTOR --------------------------------------

  ~ErrorHandler() = default;

 private:
//------------------------- PRIVATE FIELDS -------------------------------------
  ErrorCode error_;
};
}

#endif //FIRSTTASK_ERRORHANDLER_HPP
