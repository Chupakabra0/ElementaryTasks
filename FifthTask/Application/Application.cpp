//
// Created by Александр Сафиюлин on 11.12.2020.
//

#include <iostream>
#include <regex>

#include "Application.hpp"

#include "../Models/Prescription/English/EnglishPrescription.hpp"
#include "../Services/ConsoleArgsValidator/ConsoleArgsValidator.hpp"
#include "../Services/Errors/ErrorHandler/ErrorHandler.hpp"
#include "../View/View.hpp"

task::fifth::Application &task::fifth::Application::GetInstance(const unsigned int argc,
																char **argv) {
  static Application application(argc, argv);
  return application;
}

int task::fifth::Application::operator()() const {
  task::helpers::ErrorHandler errorHandler(task::helpers::ErrorCode::NO_ERROR);

  std::unique_ptr<View<std::ostream>> view(new(std::nothrow) View
											   (std::cout, errorHandler));
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

  std::unique_ptr<long long> number;

  if (consoleArgsValidator->CheckEnoughArgc(2)) {
	number = consoleArgsValidator->ValidateByIndex<long long>
		(1u, [](const char string[]) -> bool {
		  std::regex regex(R"((^|^-)(\d+?)$)");
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
