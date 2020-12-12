//
// Created by Александр Сафиюлин on 30.11.2020.
//

#pragma once

#ifndef THIRDTASK_STRINGCLEANER_HPP
#define THIRDTASK_STRINGCLEANER_HPP

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
	//result.erase(remove(result.begin(), result.end(), this->toClean_),
	//			 result.end());
	// C++20
	result.erase(std::ranges::remove(result, this->toClean_).begin(),
		result.end());
  	
	return result;
  }

 private:
  char toClean_;
};
}

#endif //THIRDTASK_STRINGCLEANER_HPP
