#include <iostream>

#include "Application.hpp"

#include <ConsoleArgsValidator/ConsoleArgsValidator.hpp>
#include <FileInputReader/FileInputReader.hpp>
#include <Errors/ErrorHandler/ErrorHandler.hpp>
#include <LuckyTicketCounter/LuckyTicketCounter.hpp>
#include <View.hpp>

//-------------------------- CTOR ----------------------------------------------

task::sixth::Application::Application(const unsigned argc, const char **argv)
	: argc_(argc), argv_(argv) {}

//----------------------- PUBLIC METHODS ---------------------------------------

// Get instance for singleton in Scott style
task::sixth::Application &task::sixth::Application::GetInstance
	(const unsigned argc, const char **argv) {
  static Application instance(argc, argv);
  return instance;
}

// Operator(), that have all main-body
int task::sixth::Application::operator()() const {
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
  std::unique_ptr<helpers::ConsoleArgsValidator> consoleArgsValidator
	  (new(std::nothrow) helpers::ConsoleArgsValidator
	  	(this->argc_, this->argv_));
  // If smth goes wrong, and nullptr returns, out error and exit app
  if (nullptr == consoleArgsValidator) {
	view->OutParseError();

	return EXIT_FAILURE;
  }

  // If there's no 2 arguments in command line
  if (!consoleArgsValidator->CheckEnoughArgc(2u)) {
    // Out instructions
	view->OutNotEnoughArgumentsMessage();

	// And app is done
	return EXIT_SUCCESS;
  }

  // Create pointer to file path, that will be initialized by the validator
  const std::unique_ptr<std::string> filePath =
	  consoleArgsValidator->ValidateByIndex<std::string>(1u);
  // If validation failed, nullptr return. And we have to out error
  if (nullptr == filePath) {
	view->OutParseError();

	return EXIT_FAILURE;
  }

  // Create pointer to file input reader
  std::unique_ptr<helpers::FileInputReader> fileInputValidator
	  (new(std::nothrow) helpers::FileInputReader
		   (std::filesystem::path(*filePath)));
  // If smth goes wrong, and nullptr returns, out error and exit app
  // And if file doesn't exist or path is invalid, do the same
  if (nullptr == fileInputValidator || !fileInputValidator->IsFileValid()) {
	view->OutPathError();

	return EXIT_FAILURE;
  }

  // Create pointer to string, that will contain the first line from the file
  std::unique_ptr<std::string> flag = fileInputValidator->ValidLine();
  // If smth goes wrong, and nullptr returns, out error and exit app
  if (nullptr == flag) {
	view->OutParseError();

	return EXIT_FAILURE;
  }

  // To make program case insensitive, make all letters to upper
  // C++14
  //std::transform(flag->begin(), flag->end(), flag->begin(), toupper);
  // C++20
  std::ranges::transform(*flag, flag->begin(), toupper);

  // Make type of lucky ticket from string
  const auto luckyTicketType = FromString(*flag);
  // If it's NONE, it's error message
  if (LuckyTicketType::NONE == luckyTicketType) {
	view->OutParseError();

	return EXIT_FAILURE;
  }

  // Set valid type to view
  view->SetTicketType(luckyTicketType);

  // Set pointer to count digits of ticket's first part
  std::unique_ptr<unsigned> countDigits(new(std::nothrow) unsigned(3u));
  // If smth goes wrong, and nullptr returns, out error and exit app
  if (nullptr == countDigits) {
	view->OutMemoryError();

	return EXIT_FAILURE;
  }

  // If there's a third argument in command line
  if (consoleArgsValidator->CheckEnoughArgc(3u)) {
    // Validate it
	std::unique_ptr<unsigned> temp = std::move(
		consoleArgsValidator->ValidateByIndex<unsigned>(2u));
	// Move temp to countDigits if everything is ok and they are not equal
	if (nullptr != temp && *countDigits != *temp) {
	  countDigits = std::move(temp);
	}
  }

  // Create lucky ticket counterm, that counts amount of 2 * countDigit lucky
  // tickets
  const std::unique_ptr<LuckyTicketCounter> ltc
	  (new(std::nothrow) LuckyTicketCounter(*countDigits));
  // If smth goes wrong, and nullptr returns, out error and exit app
  if (nullptr == ltc) {
	view->OutMemoryError();

	return EXIT_FAILURE;
  }

  // Count lucky tickets and add this info to view
  view->SetCounter(ltc->GetLuckyTicketsCount(luckyTicketType));
  // View outs counter with additional info
  view->OutCounter();

  // Success
  return EXIT_SUCCESS;
}