//
// Created by Александр Сафиюлин on 30.11.2020.
//

#pragma once

#ifndef SECONDTASK_CONSOLEINPUTVALIDATOR_HPP
#define SECONDTASK_CONSOLEINPUTVALIDATOR_HPP

#include <algorithm>
#include <iostream>
#include <string>

#include <Converter/Converter.hpp>

// TODO Move this to the all branches
namespace task::helpers {
template<class IStream>
class ConsoleInputValidator {
 public:
  ConsoleInputValidator() = delete;

  ConsoleInputValidator(const ConsoleInputValidator &) = default;

  ConsoleInputValidator(ConsoleInputValidator &&) = default;

  ConsoleInputValidator& operator=(const ConsoleInputValidator&) = default;

  ConsoleInputValidator& operator=(ConsoleInputValidator&&) = default;

  explicit ConsoleInputValidator(IStream &in) : in_(in) {}
	
  template<class Type>
  std::unique_ptr<Type> LoopInput(bool predicate(const char[]) = nullptr) {
	std::string temp;
	do {
	  getline(this->in_, temp);
	  if (this->in_) {
		std::unique_ptr<Type> data = std::move
			(Converter<Type>::ConvertString(temp, predicate));
		if (nullptr == data) {
		  std::cerr << "Input data error" << std::endl;
		} else {
		  return data;
		}
	  }

	  std::cerr << std::endl << "Try again." << std::endl;
	  this->in_.clear();
	} while (true);
  }

  template<>
  std::unique_ptr<std::string> LoopInput(bool predicate(const char[])) {
	std::string temp;
	do {
	  getline(this->in_, temp);
	  if (!std::cin || nullptr != predicate && !predicate(temp.c_str())) {
		std::cerr << "Input data error" << std::endl;
	  } else {
		return std::make_unique<std::string>(temp);
	  }

	  std::cerr << std::endl << "Try again." << std::endl;
	  this->in_.clear();
	} while (true);
  }

  template<class Type>
  std::unique_ptr<Type> Input(bool predicate(const char[]) = nullptr) {
	std::unique_ptr<Type> data;
	std::string temp;
	getline(this->in_, temp);
	if (this->in_) {
	  data = Converter<Type>::ConvertString
		  (temp, predicate);
	}
	if (nullptr == data) {
	  std::cerr << "Input data error" << std::endl;
	}
  	
	return data;
  }

  template<>
  std::unique_ptr<std::string> Input(bool predicate(const char[])) {
	std::string temp;
	getline(this->in_, temp);
	if (!this->in_ || nullptr != predicate && !predicate(temp.c_str())) {
	  std::cerr << "Input data error" << std::endl;
	}
  	
	return std::make_unique<std::string>(temp);
  }

  [[nodiscard]] const IStream& GetStream() const {
	  return this->in_;
  }

  [[nodiscard]] IStream& GetStream() {
	  return this->in_;
  }
 private:
  IStream &in_;
};
}

#endif //SECONDTASK_CONSOLEINPUTVALIDATOR_HPP
