//
// Created by Александр Сафиюлин on 30.11.2020.
//

#pragma once

#ifndef SECONDTASK_CONSOLEINPUTVALIDATOR_HPP
#define SECONDTASK_CONSOLEINPUTVALIDATOR_HPP

#include <iostream>
#include <memory>
#include <string>
#include <algorithm>

#include "../Converter/Converter.hpp"

namespace task::helpers {
class ConsoleInputValidator {
 public:
  ConsoleInputValidator() = default;

  ConsoleInputValidator(const ConsoleInputValidator &) = default;

  ConsoleInputValidator(ConsoleInputValidator &&) = default;

  template<class Type>
  std::unique_ptr<Type> LoopInput(bool predicate(const char[]) = nullptr) {
	std::string temp;
	do {
	  getline(std::cin, temp);
	  if (std::cin) {
		std::unique_ptr<Type> data = std::move
			(task::helpers::Converter<Type>::ConvertString(temp, predicate));
		if (nullptr == data) {
		  std::cerr << "Input data error" << std::endl;
		} else {
		  return data;
		}
	  }

	  std::cerr << std::endl << "Try again." << std::endl;
	  std::cin.clear();
	} while (true);
  }

  template<>
  std::unique_ptr<std::string> LoopInput(bool predicate(const char[])) {
	std::string temp;
	do {
	  getline(std::cin, temp);
	  if (!std::cin || (nullptr != predicate && !predicate(temp.c_str()))) {
		std::cerr << "Input data error" << std::endl;
	  } else {
		return std::make_unique<std::string>(temp);
	  }

	  std::cerr << std::endl << "Try again." << std::endl;
	  std::cin.clear();
	} while (true);
  }

  template<class Type>
  std::unique_ptr<Type> Input(bool predicate(const char[]) = nullptr) {
	std::unique_ptr<Type> data;
	std::string temp;
	getline(std::cin, temp);
	if (std::cin) {
	  data = task::helpers::Converter<Type>::ConvertString
		  (temp, predicate);
	}
	if (!data) {
	  std::cerr << "Input data error" << std::endl;
	}
	return data;
  }

  template<>
  std::unique_ptr<std::string> Input(bool predicate(const char[])) {
	std::string temp;
	getline(std::cin, temp);
	if (!std::cin || (nullptr != predicate && !predicate(temp.c_str()))) {
	  std::cerr << "Input data error" << std::endl;
	}
	return std::move(std::make_unique<std::string>(temp));
  }

 private:

};
}

#endif //SECONDTASK_CONSOLEINPUTVALIDATOR_HPP
