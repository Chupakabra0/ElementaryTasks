//
// Created by Александр Сафиюлин on 11.12.2020.
//

#include <iostream>

#include "Application.hpp"

#include <View.hpp>
#include <ConsoleArgsValidator/ConsoleArgsValidator.hpp>
#include <Sequence/SequenceBuilder/SequenceBuilder.hpp>

//-------------------------- CTOR ----------------------------------------------

task::eighth::Application::Application
	(const unsigned int argc, const char **argv) : argc_(argc), argv_(argv) {}

// Get instance for singleton in Scott style
task::eighth::Application &task::eighth::Application::GetInstance
	(const unsigned int argc, const char **argv) {
  static Application instance(argc, argv);
  return instance;
}

//----------------------- PUBLIC METHODS ---------------------------------------

// Get instance for singleton in Scott style
int task::eighth::Application::operator()() const {
  // Create object of class, that handles errors;
  helpers::ErrorHandler errorHandler(helpers::ErrorCode::NO_ERROR);

  // Create view
  std::unique_ptr<View<std::ostream>> view
	  (new(std::nothrow) View<std::ostream>(std::cout, errorHandler));
  // If smth goes wrong, and nullptr returns, out error and exit app
  if (nullptr == view) {
	errorHandler.SetErrorCode(helpers::ErrorCode::MEMORY_OUT);
	errorHandler.OutError("\n");

	return EXIT_FAILURE;
  }
  // In a future this work will be handled by view

  // Create console arguments validator
  const std::unique_ptr<helpers::ConsoleArgsValidator> consoleArgsValidator
	  (new(std::nothrow) helpers::ConsoleArgsValidator
	  	(this->argc_, this->argv_));
  // If smth goes wrong and nullptr returns, out error and exit app
  if (nullptr == consoleArgsValidator) {
	view->OutMemoryError();

	return EXIT_FAILURE;
  }

  // If there's no 3 arguments in command line
  if (!consoleArgsValidator->CheckEnoughArgc(3u)) {
	// Out instructions
	view->OutNotEnoughArgsMessage();

	return EXIT_SUCCESS;
  }

  // Create pointer to limits and initialize it by console args
  const std::unique_ptr<unsigned long long> lowLimit =
	  consoleArgsValidator->ValidateByIndex<unsigned long long>(1u);
  const std::unique_ptr<unsigned long long> highLimit =
	  consoleArgsValidator->ValidateByIndex<unsigned long long>(2u);
  // If args is invalid and nullptr returns, out error and exit app
  if (nullptr == lowLimit || nullptr == highLimit || *lowLimit >= *highLimit) {
	view->OutParseError();

	return EXIT_FAILURE;
  }

  // Create vector to store sequence
  std::vector<unsigned long long> numbers;

  // Create builder of sequences, that makes vector-sequence from
  // zero's element to "maxsize of vector" element.
  // Sequence make
  std::unique_ptr<SequenceBuilder<unsigned long long, Fibo>>
	  sb(new(std::nothrow) SequenceBuilder<unsigned long long, Fibo>
			 (0ull, numbers.max_size(), *lowLimit, *highLimit,
			  GenRule<unsigned long long, Fibo>()));
  // If smth goes wrong and nullptr returns, out error and exit app
  if (nullptr == sb) {
	view->OutMemoryError();

	return EXIT_FAILURE;
  }

  // Build sequence
  numbers = sb->Build();

  // Seе vector to view
  view->SetNumbers(numbers);
  // And out it
  view->OutNumbers();

  return EXIT_SUCCESS;
}