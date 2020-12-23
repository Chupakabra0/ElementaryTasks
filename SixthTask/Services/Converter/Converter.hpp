#pragma once

#ifndef HELPERS_CONVERTER_HPP
#define HELPERS_CONVERTER_HPP

#include <string>
#include <sstream>
#include <regex>

namespace task::helpers {
// "Static" class, that can convert string data to another type
template<class Type>
class Converter {
 public:
//---------------------------- CTOR --------------------------------------------

  Converter() = delete;

  Converter(const Converter &) = delete;

  Converter(Converter &&) noexcept = delete;

  Converter &operator=(const Converter &) = delete;

  Converter &operator=(Converter &&) noexcept = delete;

//------------------------- CONVERTS -------------------------------------------

  // Convert string to template type
  static std::unique_ptr<Type> ConvertString(
	  const std::string &string,
	  bool predicate(const char[]) = nullptr) {

	if (predicate && !predicate(string.c_str())) {
	  return nullptr;
	}

	// Primitive regex number check
	if (!std::regex_match(string, std::regex(R"((^|^-)(\d+?)$)"))) {
	  return nullptr;
	}

	// Create stringstream and variable, that will contain a data
	std::stringstream stringStream;
	Type typeTemp{};

	// Convert data
	stringStream << string;
	stringStream >> typeTemp;

	// If something goes wrong
	if (stringStream.fail()) {
	  // Return nullptr
	  return nullptr;
	}

	// Else return unique_ptr to data
	return std::make_unique<Type>(typeTemp);
  }

//----------------------------- DTOR -------------------------------------------
  ~Converter() = delete;
};

// Specialization for convert to unsigned
template<>
class Converter<unsigned> {
 public:
//---------------------------- CTOR --------------------------------------------

  Converter() = delete;

  Converter(const Converter &) = delete;

  Converter(Converter &&) noexcept = delete;

  Converter &operator=(const Converter &) = delete;

  Converter &operator=(Converter &&) noexcept = delete;

//------------------------- CONVERTS -------------------------------------------

  static std::unique_ptr<unsigned> ConvertString(
	  const std::string &string,
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

// Specialization for convert to double
template<>
class Converter<double> {
 public:
//---------------------------- CTOR --------------------------------------------

  Converter() = delete;

  Converter(const Converter &) = delete;

  Converter(Converter &&) noexcept = delete;

  Converter &operator=(const Converter &) = delete;

  Converter &operator=(Converter &&) noexcept = delete;

//------------------------- CONVERTS -------------------------------------------

  static std::unique_ptr<double> ConvertString(
	  const std::string &string,
	  bool predicate(const char[]) = nullptr) {

	if (predicate && !predicate(string.c_str())) {
	  return nullptr;
	}

	if (!std::regex_match(string,
						  std::regex(R"((^-|^)(\d+?|)($|\.|\.\d+?$))"))) {
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

// Specialization for convert to float
template<>
class Converter<float> {
 public:
//---------------------------- CTOR --------------------------------------------

  Converter() = delete;

  Converter(const Converter &) = delete;

  Converter(Converter &&) noexcept = delete;

  Converter &operator=(const Converter &) = delete;

  Converter &operator=(Converter &&) noexcept = delete;

//------------------------- CONVERTS -------------------------------------------

  static std::unique_ptr<float> ConvertString(
	  const std::string &string,
	  bool predicate(const char[]) = nullptr) {

	if (predicate && !predicate(string.c_str())) {
	  return nullptr;
	}

	if (!std::regex_match(string,
						  std::regex(R"((^-|^)(\d+?|)(\.(\d+?)(f$|$)|\.f$|$))"))) {
	  return nullptr;
	}

	std::stringstream stringStream;

	float typeTemp{};

	stringStream << string;
	stringStream >> typeTemp;

	if (stringStream.fail()) {
	  return nullptr;
	}

	return std::make_unique<float>(typeTemp);
  }

  ~Converter() = delete;
};

}
#endif //HELPERS_CONVERTER_HPP