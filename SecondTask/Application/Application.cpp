//
// Created by Александр Сафиюлин on 09.12.2020.
//

#include <algorithm>
#include <iostream>
#include <string>
#include <regex>

#include "Application.hpp"

#include <Envelope/Envelope/Envelope.hpp>
#include <View.hpp>
#include <ConsoleInputValidator/ConsoleInputValidator.hpp>

task::second::Application &task::second::Application::GetInstance() {
  static Application instance;
  return instance;
}

int task::second::Application::operator()() const {
  std::string flag;
  helpers::ErrorHandler errorHandler(helpers::ErrorCode::NO_ERROR);

  std::unique_ptr<View<std::ostream>> view
	  (new(std::nothrow) View<std::ostream>(std::cout, errorHandler));
  if (nullptr == view) {
	errorHandler.SetErrorCode(helpers::ErrorCode::MEMORY_OUT);
	errorHandler.OutError(std::string("\n"));

	return EXIT_FAILURE;
  }

  std::unique_ptr<helpers::ConsoleInputValidator<std::istream>> consoleValidator
	  (new(std::nothrow) helpers::ConsoleInputValidator<std::istream>(std::cin));
  if (nullptr == consoleValidator) {
	view->OutMemoryError();

	return EXIT_FAILURE;
  }

  auto positiveDouble = [](const char string[]) -> bool {
	const std::regex number(R"((^\d+?(\.\d+?$|$)))");
	return std::regex_match(string, number)
		&& std::string(string).find('-') == std::string::npos;
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

	view->OutPutInResult();

	std::cout << "Continue? [y/Yes]: ";
	std::cin >> flag;
	std::cin.ignore();

  	// C++11
	//std::transform(flag.begin(), flag.end(), flag.begin(), toupper);

  	// C++20
	std::ranges::transform(flag, flag.begin(), toupper);
  } while ("Y" == flag || "YES" == flag);

  return EXIT_SUCCESS;
}
