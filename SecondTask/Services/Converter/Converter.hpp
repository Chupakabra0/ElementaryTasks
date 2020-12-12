//
// Created by Александр Сафиюлин on 25.11.2020.
//

#pragma once

#ifndef HELPERS_CONVERTER_HPP
#define HELPERS_CONVERTER_HPP

#include <string>
#include <sstream>

namespace task::helpers {
template<class Type>
class Converter {
 public:
  Converter() = delete;

  Converter(const Converter &) = delete;

  Converter(Converter &&) = delete;

  static std::unique_ptr<Type> ConvertString(
	  const std::string &string,
	  bool predicate(const char[]) = nullptr) {

	if (predicate && !predicate(string.c_str())) {
	  return nullptr;
	}

	std::stringstream stringStream;
	Type temp{};

	stringStream << string;
	stringStream >> temp;

	if (stringStream.fail()) {
	  return nullptr;
	}

	return std::make_unique<Type>(temp);
  }

  ~Converter() = delete;
};

}
#endif //HELPERS_CONVERTER_HPP
