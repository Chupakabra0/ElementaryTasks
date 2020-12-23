//
// Created by Александр Сафиюлин on 11.12.2020.
//

#include <iostream>
#include <regex>

#include "Application.hpp"

#include <View.hpp>
#include <ConsoleArgsValidator/ConsoleArgsValidator.hpp>
#include <Sequence/SequenceBuilder/SequenceBuilder.hpp>

task::eighth::Application &task::eighth::Application::GetInstance(const unsigned int argc,
																  const char
																  **argv) {
  static Application instance(argc, argv);
  return instance;
}

int task::eighth::Application::operator()() const {
  helpers::ErrorHandler errorHandler(helpers::ErrorCode::NO_ERROR);

  std::unique_ptr<View<std::ostream>> view
	  (new(std::nothrow) View<std::ostream>(std::cout, errorHandler));
  if (nullptr == view) {
	errorHandler.SetErrorCode(helpers::ErrorCode::MEMORY_OUT);
	errorHandler.OutError("\n");

	return EXIT_FAILURE;
  }

  const std::unique_ptr<helpers::ConsoleArgsValidator> consoleArgsValidator
	  (new(std::nothrow) helpers::ConsoleArgsValidator(this->argc_,
													   this->argv_));
  if (nullptr == consoleArgsValidator) {
	view->OutMemoryError();

	return EXIT_FAILURE;
  }

  if (!consoleArgsValidator->CheckEnoughArgc(3u)) {
	view->OutNotEnoughArgsMessage();

	return EXIT_SUCCESS;
  }

  const auto checkLetters = [](const char string[]) -> bool {
	const std::regex lettersCheck(R"((\d+?))");
	return std::regex_match(string, lettersCheck);
  };

  const std::unique_ptr<unsigned long long> lowLimit =
	  consoleArgsValidator
		  ->ValidateByIndex<unsigned long long>(1u, checkLetters);
  const std::unique_ptr<unsigned long long> highLimit =
	  consoleArgsValidator
		  ->ValidateByIndex<unsigned long long>(2u, checkLetters);
  if (nullptr == lowLimit || nullptr == highLimit) {
	view->OutParseError();

	return EXIT_FAILURE;
  }

  std::vector<unsigned long long> numbers;

  std::unique_ptr<SequenceBuilder<unsigned long long, Fibo>>
	  sb(new(std::nothrow) SequenceBuilder<unsigned long long, Fibo>
			 (0ull, numbers.max_size(), *lowLimit, *highLimit,
			  GenRule<unsigned long long, Fibo>()));
  if (nullptr == sb) {
	view->OutMemoryError();

	return EXIT_FAILURE;
  }

  numbers = sb->Build();

  view->SetNumbers(numbers);
  view->OutNumbers();

  return EXIT_SUCCESS;
}