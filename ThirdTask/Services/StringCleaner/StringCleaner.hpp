//
// Created by Александр Сафиюлин on 30.11.2020.
//

#pragma once

#ifndef THIRDTASK_STRINGCLEANER_HPP
#define THIRDTASK_STRINGCLEANER_HPP

#include <algorithm>
#include <string>

namespace task::helpers {
class StringCleaner {
 public:
  StringCleaner() = delete;

  StringCleaner(const StringCleaner &) = default;

  StringCleaner(StringCleaner &&) noexcept = default;

  StringCleaner& operator=(const StringCleaner&) = default;

  StringCleaner& operator=(StringCleaner&&) noexcept = default;

  explicit StringCleaner(const char toClean) : toClean_(toClean) {}

  [[nodiscard]] std::string Clean(const std::string &string) const {
	auto result = string;
  	// C++11
	//result.erase(std::ranges::remove(result, this->toClean_).begin(),
	//			 result.end());
	// C++20
	result.erase(std::ranges::remove(result, this->toClean_).begin(),
		result.end());
  	
	return result;
  }

  [[nodiscard]] char GetSymbolToClean() const {
	return this->toClean_;
  }

  void SetSymbolToClean(const char symbol) {
	if (this->toClean_ == symbol) {
	  return;
	}
	this->toClean_ = symbol;
  }

 private:
  char toClean_;
};
}

#endif //THIRDTASK_STRINGCLEANER_HPP
