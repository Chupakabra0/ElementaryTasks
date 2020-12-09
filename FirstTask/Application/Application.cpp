//
// Created by Александр Сафиюлин on 09.12.2020.
//

#include "Application.hpp"

#include "../Models/Board/BoardCreator.hpp"
#include "../ViewModels/ViewModel.hpp"
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

  std::unique_ptr<unsigned short> rowsCount, columnsCount;
  std::unique_ptr<task::helpers::ConsoleArgsValidator> consoleArgsValidator
	  (new(std::nothrow) task::helpers::ConsoleArgsValidator
		   (this->argc_, this->argv_));
  if (nullptr == consoleArgsValidator) {
	errorHandler.SetErrorCode(task::helpers::ErrorCode::MEMORY_OUT);
	errorHandler.OutError(std::string("\n"));

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
	  errorHandler.SetErrorCode(task::helpers::ErrorCode::PARSE_FAILED);
	  errorHandler.OutError(std::string("\n"));

	  return EXIT_FAILURE;
	}

	columnsCount = consoleArgsValidator->ValidateByIndex<unsigned
														 short>(2,
																checkLetters);
	if (nullptr == columnsCount) {
	  errorHandler.SetErrorCode(task::helpers::ErrorCode::PARSE_FAILED);
	  errorHandler.OutError(std::string("\n"));

	  return EXIT_FAILURE;
	}
  } else {
	errorHandler.SetErrorCode(task::helpers::ErrorCode::NOT_ENOUGH_ARGS);
	errorHandler.OutError(std::string("\n"));

    std::cout << "FirstTask.exe rowsCount columnsCount" << std::endl;

	return EXIT_SUCCESS;
  }

  std::unique_ptr<task::first::BoardCreator<char>> boardFactory
	  (new(std::nothrow) task::first::BoardCreator('*', ' '));
  if (nullptr == boardFactory) {
	errorHandler.SetErrorCode(task::helpers::ErrorCode::PARSE_FAILED);
	errorHandler.OutError(std::string("\n"));

	return EXIT_FAILURE;
  }

  std::unique_ptr<task::first::Board<char>> board
	  = boardFactory->CreateBoard(*rowsCount, *columnsCount);
  if (nullptr == board) {
	errorHandler.SetErrorCode(task::helpers::ErrorCode::MEMORY_OUT);
	errorHandler.OutError(std::string("\n"));

	return EXIT_FAILURE;
  }

  std::unique_ptr<task::first::ViewModel<char>> viewModel
	  (new(std::nothrow) task::first::ViewModel(*board));
  if (nullptr == viewModel) {
	errorHandler.SetErrorCode(task::helpers::ErrorCode::MEMORY_OUT);
	errorHandler.OutError(std::string("\n"));

	return EXIT_FAILURE;
  }

  std::unique_ptr<task::first::View<char>> view
	  (new(std::nothrow) task::first::View(*viewModel));
  if (nullptr == view) {
	errorHandler.SetErrorCode(task::helpers::ErrorCode::MEMORY_OUT);
	errorHandler.OutError(std::string("\n"));

	return EXIT_FAILURE;
  }

  view->Out();

  return EXIT_SUCCESS;
}
