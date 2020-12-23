#pragma once

#ifndef FIRSTTASK_SERVICES_ERRORS_ERRORCODE_ERRORTYPE_HPP_
#define FIRSTTASK_SERVICES_ERRORS_ERRORCODE_ERRORTYPE_HPP_

#include <sstream>
#include <string>

namespace task::helpers {
// Error codes
enum class ErrorCode : unsigned short {
  NO_ERROR,
  MEMORY_OUT,
  PARSE_FAILED,
  VALIDATION_FAILED,
  FILE_NOT_EXIST,
  NOT_ENOUGH_ARGS,
  ETERNAL_SERVER_ERROR
};

// To out error code we have to convert it to string
inline std::string ToString(ErrorCode errorCode) {
  std::stringstream ss;
  ss << "Code " << static_cast<unsigned short>(errorCode) << ": ";
  switch (errorCode) {
	case ErrorCode::MEMORY_OUT: {
	  ss << "Memory out...";
	  break;
	}
	case ErrorCode::PARSE_FAILED: {
	  ss << "Parse failed...";
	  break;
	}
	case ErrorCode::VALIDATION_FAILED: {
	  ss << "Validation failed...";
	  break;
	}
	case ErrorCode::FILE_NOT_EXIST: {
	  ss << "File doesn't exist...";
	  break;
	}
	case ErrorCode::NOT_ENOUGH_ARGS: {
	  ss << "Not enough arguments...";
	  break;
	}
	case ErrorCode::ETERNAL_SERVER_ERROR: {
	  ss << "Eternal server error...";
	  break;
	}
	default: {
	  ss << "No error";
	  break;
	}
  }

  return std::string(ss.str());
}

}
#endif //FIRSTTASK_SERVICES_ERRORS_ERRORCODE_ERRORTYPE_HPP_
