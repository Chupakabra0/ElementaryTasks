//
// Created by Александр Сафиюлин on 09.12.2020.
//

#include "Application.hpp"

#include "../Models/Board/BoardCreator.hpp"
#include "../View/View.hpp"
#include "../Services/ConsoleArgsValidator/ConsoleArgsValidator.hpp"

task::first::Application::Application(const unsigned int argc, char **argv)
	: argc_(argc), argv_(argv) {}

task::first::Application &
task::first::Application::GetInstance(const unsigned int argc, char **argv) {
  static Application instance(argc, argv);
  return instance;
}

int task::first::Application::operator()() {
  task::helpers::ErrorHandler errorHandler(task::helpers::ErrorCode::NO_ERROR);

  std::unique_ptr<View<Board<char>, std::ostream>> view
	  (new(std::nothrow) task::first::View<Board<char>,
										   std::ostream>(std::cout, errorHandler));
  if (nullptr == view) {
	errorHandler.SetErrorCode(task::helpers::ErrorCode::MEMORY_OUT);
	errorHandler.OutError(std::string("\n"));

	return EXIT_FAILURE;
  }

  std::unique_ptr<unsigned short> rowsCount, columnsCount;
  std::unique_ptr<task::helpers::ConsoleArgsValidator> consoleArgsValidator
	  (new(std::nothrow) task::helpers::ConsoleArgsValidator
		   (this->argc_, this->argv_));
  if (nullptr == consoleArgsValidator) {
	view->OutMemoryError();

	return EXIT_FAILURE;
  }

  const auto checkLetters = [](const char string[]) -> bool {
	const std::regex lettersCheck(R"((\d+?))");
	return std::regex_match(string, lettersCheck);
  };

  if (consoleArgsValidator->CheckEnoughArgc(3)) {
	rowsCount = consoleArgsValidator->ValidateByIndex<unsigned
													  short>(1, checkLetters);
	if (nullptr == rowsCount) {
	  view->OutParseError();

	  return EXIT_FAILURE;
	}

	columnsCount = consoleArgsValidator->ValidateByIndex<unsigned
														 short>(2,
																checkLetters);
	if (nullptr == columnsCount) {
	  view->OutParseError();

	  return EXIT_FAILURE;
	}
  } else {
	view->OutNotEnoughArgsMessage();

	return EXIT_SUCCESS;
  }

  std::unique_ptr<task::first::BoardCreator<char>> boardCreator
	  (new(std::nothrow) task::first::BoardCreator('*', ' '));
  if (nullptr == boardCreator) {
	view->OutParseError();

	return EXIT_FAILURE;
  }

  std::unique_ptr<task::first::Board<char>> board
	  = boardCreator->CreateBoard(*rowsCount, *columnsCount);
  if (nullptr == board) {
	view->OutMemoryError();

	return EXIT_FAILURE;
  }

  view->SetChessBoard(*board);
  view->OutBoard();

  return EXIT_SUCCESS;
}
