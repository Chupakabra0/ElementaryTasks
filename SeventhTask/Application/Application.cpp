//
// Created by Александр Сафиюлин on 11.12.2020.
//

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
  task::helpers::ErrorHandler errorHandler(task::helpers::ErrorCode::NO_ERROR);

  std::unique_ptr<task::seventh::View<std::ostream>> view
	  (new(std::nothrow) View(std::cout, errorHandler));
  if (nullptr == view) {
	errorHandler.SetErrorCode(helpers::ErrorCode::MEMORY_OUT);
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

  if (!consoleArgsValidator->CheckEnoughArgc(2u)) {
	view->OutNotEnoughArgsMessage();

	return EXIT_SUCCESS;
  }

  std::unique_ptr<unsigned long long> number =
  	consoleArgsValidator->ValidateByIndex<unsigned long long>(1u,
	[](const char string[]) -> bool {
	  std::regex regex(R"(^(\d+?)$)");
	  return std::regex_match(string, regex);
    });
  if (nullptr == number) {
    view->OutParseError();

	return EXIT_FAILURE;
  }

  *number = ceil(std::sqrt(*number));

  std::unique_ptr<task::seventh::SequenceBuilder<unsigned long long>>
  sequenceBuilder
	  (new(std::nothrow) task::seventh::SequenceBuilder(0ull, *number));
  if (nullptr == sequenceBuilder) {
	view->OutParseError();

	return EXIT_FAILURE;
  }

  view->SetNumbers(sequenceBuilder->Build());
  view->OutNumbers();

  return EXIT_SUCCESS;
}

