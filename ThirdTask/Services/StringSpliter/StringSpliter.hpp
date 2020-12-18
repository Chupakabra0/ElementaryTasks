//
// Created by Александр Сафиюлин on 30.11.2020.
//

#pragma once

#ifndef THIRDTASK_STRINGSPLITER_HPP
#define THIRDTASK_STRINGSPLITER_HPP

#include <string>
#include <sstream>
#include <vector>

namespace task::helpers {
class StringSpliter {
 public:
  StringSpliter() = delete;

  StringSpliter(const StringSpliter &) = default;

  StringSpliter(StringSpliter &&) noexcept = default;

  StringSpliter &operator=(const StringSpliter &) = default;

  StringSpliter &operator=(StringSpliter &&) noexcept = default;

  explicit StringSpliter(const char delimiter) : delimiter_(delimiter) {}

  [[nodiscard]] std::vector<std::string>
  Split(const std::string &string) const {
	std::vector<std::string> result;
	std::string token;
	std::stringstream ss(string);
	while (getline(ss, token, this->delimiter_)) {
	  if ("" == token) {
		  continue;
	  }
	  result.push_back(token);
	}

	return result;
  }

  [[nodiscard]] char GetDelimiter() const {
	 return this->delimiter_;
  }

  void SetDelimiter(const char symbol) {
    if (symbol == this->delimiter_) {
	  return;
    }
	this->delimiter_ = symbol;
  }

 private:
  char delimiter_;
};
}

#endif //THIRDTASK_STRINGSPLITER_HPP
