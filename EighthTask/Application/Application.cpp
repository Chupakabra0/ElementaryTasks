//
// Created by Александр Сафиюлин on 11.12.2020.
//

#include <iostream>
#include <regex>

#include "Application.hpp"

#include "../View/View.hpp"
#include "../Services/ConsoleArgsValidator/ConsoleArgsValidator.hpp"
#include "../Models/FibonacciBuilder/FibonacciBuilder.hpp"

task::eighth::Application &task::eighth::Application::GetInstance(const unsigned int argc,
																  char **argv) {
  static Application instance(argc, argv);
  return instance;
}

int task::eighth::Application::operator()() const {
  task::helpers::ErrorHandler errorHandler(task::helpers::ErrorCode::NO_ERROR);

  std::unique_ptr<task::eighth::View<std::ostream>> view
	  (new(std::nothrow) task::eighth::View(std::cout, errorHandler));
  if (nullptr == view) {
	errorHandler.SetErrorCode(task::helpers::ErrorCode::MEMORY_OUT);
	errorHandler.OutError("\n");

	return EXIT_FAILURE;
  }

  std::unique_ptr<task::helpers::ConsoleArgsValidator> consoleArgsValidator
	  (new(std::nothrow) task::helpers::ConsoleArgsValidator(this->argc_,
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

  std::unique_ptr<unsigned long long> lowLimit =
	  consoleArgsValidator
		  ->ValidateByIndex<unsigned long long>(1u, checkLetters);
  std::unique_ptr<unsigned long long> highLimit =
	  consoleArgsValidator
		  ->ValidateByIndex<unsigned long long>(2u, checkLetters);
  if (nullptr == lowLimit || nullptr == highLimit) {
	view->OutParseError();

	return EXIT_FAILURE;
  }

  std::unique_ptr<task::eighth::FibonacciBuilder<unsigned long long>>
	  fibonacciBuilder(new(std::nothrow) task::eighth::FibonacciBuilder
						   (*lowLimit, *highLimit));
  if (nullptr == fibonacciBuilder) {
	view->OutMemoryError();

	return EXIT_FAILURE;
  }

  view->SetNumbers(fibonacciBuilder->Build());
  view->OutNumbers();

  return EXIT_SUCCESS;
}
