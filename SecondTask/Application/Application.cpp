//
// Created by Александр Сафиюлин on 09.12.2020.
//

#include <algorithm>
#include <iostream>
#include <string>
#include <regex>

#include "Application.hpp"

#include "../Models/Envelope/Envelope.hpp"
#include "../View/View.hpp"
#include "../Services/ConsoleInputValidator/ConsoleInputValidator.hpp"
#include "../Services/Errors/ErrorHandler/ErrorHandler.hpp"

task::second::Application &task::second::Application::GetInstance() {
  static Application instance;
  return instance;
}

int task::second::Application::operator()() const {
  std::string flag;
  task::helpers::ErrorHandler errorHandler(task::helpers::ErrorCode::NO_ERROR);

  std::unique_ptr<
	  task::helpers::ConsoleInputValidator> consoleValidator
	  (new(std::nothrow) task::helpers::ConsoleInputValidator());
  if (nullptr == consoleValidator) {
	errorHandler.SetErrorCode(task::helpers::ErrorCode::MEMORY_OUT);
	errorHandler.OutError(std::string("\n"));

	return EXIT_FAILURE;
  }

  std::unique_ptr<task::second::View<std::ostream>> view
	  (new(std::nothrow) task::second::View(std::cout));
  if (nullptr == view) {
	errorHandler.SetErrorCode(task::helpers::ErrorCode::MEMORY_OUT);
	errorHandler.OutError(std::string("\n"));

	return EXIT_FAILURE;
  }

  auto positiveDouble = [](const char string[]) -> bool {
	const std::regex number(R"((^\d+?(\.\d+?$|$)))");
	return std::regex_match(string, number)
		&&
			std::string(string).find('-') == std::string::npos;
  };

  do {
	std::cout << "Creating first envelope." << std::endl
			  << "Enter height:" << std::endl;
	std::unique_ptr<double> firstHeight = consoleValidator->LoopInput<double>
		(positiveDouble);

	std::cout << "Enter width:" << std::endl;
	std::unique_ptr<double> firstWidth = consoleValidator->LoopInput<double>
		(positiveDouble);

	std::cout << "Creating second envelope." << std::endl
			  << "Enter height:" << std::endl;
	std::unique_ptr<double> secondHeight = consoleValidator->LoopInput<double>
		(positiveDouble);
	std::cout << "Enter width:" << std::endl;
	std::unique_ptr<double> secondWidth = consoleValidator->LoopInput<double>
		(positiveDouble);

	view->SetFirstEnvelope(Envelope(*firstHeight, *firstWidth));
	view->SetSecondEnvelope(Envelope(*secondHeight, *secondWidth));

	view->Out();

	std::cout << "Continue? [y/Yes]:";
	std::cin >> flag;
	std::cin.ignore();
	std::transform(flag.begin(), flag.end(), flag.begin(), toupper);
  } while ("Y" == flag || "YES" == flag);

  return EXIT_SUCCESS;
}
