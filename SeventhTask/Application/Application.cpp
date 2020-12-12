//
// Created by Александр Сафиюлин on 11.12.2020.
//

#include <iostream>
#include <regex>
#include <cmath>

#include "Application.hpp"

#include "../View/View.hpp"
#include "../Services/ConsoleArgsValidator/ConsoleArgsValidator.hpp"
#include "../Models/SequenceBuilder/SequenceBuilder.hpp"

task::seventh::Application &task::seventh::Application::GetInstance
	(const unsigned int argc, char **argv) {
  static Application instance(argc, argv);
  return instance;
}

int task::seventh::Application::operator()() const {
  helpers::ErrorHandler errorHandler(helpers::ErrorCode::NO_ERROR);

  std::unique_ptr<View<std::ostream>> view
	  (new(std::nothrow) View<std::ostream>(std::cout, errorHandler));
  if (nullptr == view) {
	errorHandler.SetErrorCode(helpers::ErrorCode::MEMORY_OUT);
	errorHandler.OutError("\n");

	return EXIT_FAILURE;
  }

  const std::unique_ptr<helpers::ConsoleArgsValidator> consoleArgsValidator
	  (new(std::nothrow) helpers::ConsoleArgsValidator(this->argc_, this->argv_));
  if (nullptr == consoleArgsValidator) {
	view->OutMemoryError();

	return EXIT_FAILURE;
  }

  if (!consoleArgsValidator->CheckEnoughArgc(2u)) {
	view->OutNotEnoughArgsMessage();

	return EXIT_SUCCESS;
  }

  std::unique_ptr<unsigned long long> number =
  	consoleArgsValidator->ValidateByIndex<unsigned long long>(1u,
	[](const char string[]) -> bool {
		const std::regex regex(R"(^(\d+?)$)");
	  return std::regex_match(string, regex);
    });
  if (nullptr == number) {
    view->OutParseError();

	return EXIT_FAILURE;
  }

  *number = static_cast<unsigned long long>(ceil(std::sqrt(*number)));

  const std::unique_ptr<SequenceBuilder<unsigned long long>>
  sequenceBuilder(new(std::nothrow) SequenceBuilder<unsigned long long>
	  (0ull, *number));
  if (nullptr == sequenceBuilder) {
	view->OutParseError();

	return EXIT_FAILURE;
  }

  view->SetNumbers(sequenceBuilder->Build());
  view->OutNumbers();

  return EXIT_SUCCESS;
}

