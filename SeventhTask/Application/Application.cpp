//
// Created by Александр Сафиюлин on 11.12.2020.
//

#include <iostream>
#include <cmath>

#include "Application.hpp"

#include <View.hpp>
#include <ConsoleArgsValidator/ConsoleArgsValidator.hpp>
#include <Sequence/SequenceBuilder/SequenceBuilder.hpp>

task::seventh::Application &task::seventh::Application::GetInstance
	(const unsigned int argc, const char **argv) {
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
	  (new(std::nothrow) helpers::ConsoleArgsValidator(this->argc_,
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
	  consoleArgsValidator->ValidateByIndex<unsigned long long>(1u);
  if (nullptr == number || *number > 7899786854775807ull) {
	view->OutParseError();

	return EXIT_FAILURE;
  }

  std::vector<unsigned long long> l;
  std::cout << std::endl << l.max_size() << std::endl;

  *number = static_cast<unsigned long long>(ceil(std::sqrt(*number)));

  seventh::SequenceBuilder<unsigned long long> sb
	  (0ull, *number, GenRule<unsigned long long, AfterOne>());

  view->SetNumbers(sb.Build());
  view->OutNumbers();

  return EXIT_SUCCESS;
}

