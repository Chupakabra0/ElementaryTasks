//
// Created by Александр Сафиюлин on 27.11.2020.
//

#pragma once

#ifndef FIRSTTASK_CONSOLEARGSVALIDATOR_HPP
#define FIRSTTASK_CONSOLEARGSVALIDATOR_HPP

#include <array>

#include <Converter/Converter.hpp>

namespace task::helpers {
class ConsoleArgsValidator {
 public:
  ConsoleArgsValidator() = delete;

  ConsoleArgsValidator(const ConsoleArgsValidator&) = delete;

  ConsoleArgsValidator(ConsoleArgsValidator &&) = default;

  ConsoleArgsValidator& operator=(const ConsoleArgsValidator&) = delete;

  ConsoleArgsValidator& operator=(ConsoleArgsValidator&&) = default;

  ConsoleArgsValidator(const unsigned argc, const char **argv)
	  : argc_(argc), argv_(argv) {
	  
  }

  template<class Type>
  std::unique_ptr<Type> ValidateByIndex(
	  const unsigned index, bool
  predicate(const char[]) = nullptr) const {
	auto result = std::move(
		Converter<Type>::ConvertString
			(this->argv_[index], predicate));

	return result;
  }

  template<>
  std::unique_ptr<std::string> ValidateByIndex(
	  const unsigned index, bool
  predicate(const char[])) const {
	if (nullptr != predicate && !predicate(this->argv_[index])) {
	  return nullptr;
	}

	return std::make_unique<std::string>(std::string(this->argv_[index]));
  }

  [[nodiscard]] bool CheckEnoughArgc(const unsigned argc) const {
	return this->argc_ >= argc;
  }

  [[nodiscard]] const char *GetPath() const {
	return this->argv_[0];
  }

  [[nodiscard]] unsigned GetArgc() const {
	return this->argc_;
  }

  [[nodiscard]] const char **GetArgv() const {
	return this->argv_;
  }

  ~ConsoleArgsValidator() = default;

 private:
  unsigned argc_;
  const char **argv_;
};
}

#endif //FIRSTTASK_CONSOLEARGSVALIDATOR_HPP
