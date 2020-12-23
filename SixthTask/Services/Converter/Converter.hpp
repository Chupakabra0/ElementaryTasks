//
// Created by Александр Сафиюлин on 25.11.2020.
//

#pragma once

#ifndef HELPERS_CONVERTER_HPP
#define HELPERS_CONVERTER_HPP

#include <string>
#include <sstream>
#include <regex>

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

  	if (!std::regex_match(string, std::regex(R"((^|^-)(\d+?)$)"))) {
		return nullptr;
  	}

	std::stringstream stringStream;
  	
	Type typeTemp{};

	stringStream << string;
	stringStream >> typeTemp;

	if (stringStream.fail()) {
		return nullptr;
	}

	return std::make_unique<Type>(typeTemp);
  }

  ~Converter() = delete;
};

template<>
class Converter<unsigned> {
public:
	Converter() = delete;

	Converter(const Converter&) = delete;

	Converter(Converter&&) = delete;

	static std::unique_ptr<unsigned> ConvertString(
		const std::string& string,
		bool predicate(const char[]) = nullptr) {

		if (predicate && !predicate(string.c_str())) {
			return nullptr;
		}

		if (!std::regex_match(string, std::regex(R"((^(\d+?)($|u$)))"))) {
			return nullptr;
		}

		std::stringstream stringStream;

		unsigned typeTemp{};

		stringStream << string;
		stringStream >> typeTemp;

		if (stringStream.fail()) {
			return nullptr;
		}


		return std::make_unique<unsigned>(typeTemp);
	}

	~Converter() = delete;
};
	
template<>
class Converter<double> {
public:
	Converter() = delete;

	Converter(const Converter&) = delete;

	Converter(Converter&&) = delete;

	static std::unique_ptr<double> ConvertString(
		const std::string& string,
		bool predicate(const char[]) = nullptr) {

		if (predicate && !predicate(string.c_str())) {
			return nullptr;
		}
		
		if (!std::regex_match(string, std::regex(R"((^-|^)(\d+?|)($|\.|\.\d+?$))"))) {
			return nullptr;
		}
		
		std::stringstream stringStream;
		double typeTemp{};

		stringStream << string;
		stringStream >> typeTemp;

		if (stringStream.fail()) {
			return nullptr;
		}

		return std::make_unique<double>(typeTemp);
	}

	~Converter() = delete;
};

template<>
class Converter<float> {
public:
	Converter() = delete;

	Converter(const Converter&) = delete;

	Converter(Converter&&) = delete;

	static std::unique_ptr<float> ConvertString(
		const std::string& string,
		bool predicate(const char[]) = nullptr) {

		if (predicate && !predicate(string.c_str())) {
			return nullptr;
		}

		if (!std::regex_match(string, std::regex(R"((^-|^)(\d+?|)(\.(\d+?)(f$|$)|\.f$|$))"))) {
			return nullptr;
		}
		
		std::stringstream stringStream;

		float typeTemp{};

		stringStream << string;
		stringStream >> typeTemp;

		if (stringStream.fail()) {
			return nullptr;
		}

		if (stringStream.fail()) {
			return nullptr;
		}


		return std::make_unique<float>(typeTemp);
	}

	~Converter() = delete;
};
	
}
#endif //HELPERS_CONVERTER_HPP