//
// Created by Александр Сафиюлин on 11.12.2020.
//

#include <iostream>
#include <regex>

#include "Application.hpp"

#include <Prescription/English/EnglishPrescription.hpp>
#include <ConsoleArgsValidator/ConsoleArgsValidator.hpp>
#include <Errors/ErrorHandler/ErrorHandler.hpp>
#include <View.hpp>

task::fifth::Application::Application(const unsigned argc, const char** argv)
	: argc_(argc), argv_(argv) {}

task::fifth::Application &task::fifth::Application::GetInstance(const unsigned int argc,
                                                                const char **argv) {
  static Application application(argc, argv);
  return application;
}

int task::fifth::Application::operator()() const {
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

  std::unique_ptr<long long> number;

  if (consoleArgsValidator->CheckEnoughArgc(2)) {
	number = consoleArgsValidator->ValidateByIndex<long long>
		(1u, [](const char string[]) -> bool {
			const std::regex regex(R"((^|^-)(\d+?)$)");
		  return std::regex_match(string, regex);
		});

	if (nullptr == number) {
	  view->OutParseError();

	  return EXIT_FAILURE;
	}
  } else {
	view->OutNotEnoughArgsMessage();

	return EXIT_SUCCESS;
  }

  std::unique_ptr<Prescription> prescription(new(std::nothrow)
												 EnglishPrescription());
  if (nullptr == prescription) {
	view->OutMemoryError();

	return EXIT_FAILURE;
  }

  view->SetDigit(*number);
  view->SetStr(prescription->ToSmallPrescription(*number));

  view->OutDigitAndLetter();

  return EXIT_SUCCESS;
}