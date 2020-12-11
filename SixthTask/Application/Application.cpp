//
// Created by Александр Сафиюлин on 11.12.2020.
//

#include <iostream>
#include <regex>

#include "Application.hpp"

#include "../Services/ConsoleArgsValidator/ConsoleArgsValidator.hpp"
#include "../Services/FileInputValidator/FileInputValidator.hpp"
#include "../Services/Errors/ErrorHandler/ErrorHandler.hpp"

#include "../Models/LuckyTicketCounter/LuckyTicketCounter.hpp"

#include "../View/View.hpp"

task::sixth::Application &task::sixth::Application::GetInstance(unsigned int argc,
																char **argv) {
  static Application instance(argc, argv);
  return instance;
}

int task::sixth::Application::operator()() const {
  task::helpers::ErrorHandler errorHandler(task::helpers::ErrorCode::NO_ERROR);

  std::unique_ptr<task::sixth::View<std::ostream>> view
  (new(std::nothrow) task::sixth::View(std::cout, errorHandler));
  if(nullptr == view) {
	errorHandler.SetErrorCode(task::helpers::ErrorCode::MEMORY_OUT);
	errorHandler.OutError("\n");

	return EXIT_FAILURE;
  }


  std::unique_ptr<task::helpers::ConsoleArgsValidator> consoleArgsValidator
	  (new(std::nothrow) task::helpers::ConsoleArgsValidator(this->argc_,
															 this->argv_));
  if (nullptr == consoleArgsValidator) {
	view->OutParseError();

	return EXIT_FAILURE;
  }

  if (!consoleArgsValidator->CheckEnoughArgc(2u)) {
	view->OutNotEnoughArgumentsMessage();

	return EXIT_SUCCESS;
  }

  std::unique_ptr<std::string> filePath = std::move
	  (consoleArgsValidator->ValidateByIndex<std::string>(1u));
  if (nullptr == filePath) {
	view->OutParseError();

	return EXIT_FAILURE;
  }

  std::unique_ptr<task::helpers::FileInputValidator> fileInputValidator
 	 (new(std::nothrow) task::helpers::FileInputValidator
 	 	(std::filesystem::path(*filePath)));
  if (nullptr == fileInputValidator) {
	view->OutParseError();

	return EXIT_FAILURE;
  }
  if (!fileInputValidator->IsFileValid()) {
	view->OutPathError();

	return EXIT_FAILURE;
  }

  std::unique_ptr<std::string> flag = fileInputValidator->ValidLine();
  if (nullptr == flag) {
	view->OutParseError();

	return EXIT_FAILURE;
  }
  std::transform(flag->begin(), flag->end(), flag->begin(), toupper);

  auto luckyTicketType = task::sixth::FromString(*flag);
  if (task::sixth::LuckyTicketType::NONE == luckyTicketType) {
	view->OutParseError();

	return EXIT_FAILURE;
  }

  view->SetTicketType(luckyTicketType);

  std::unique_ptr<unsigned> countDigits(new(std::nothrow) unsigned(3u));
  if (nullptr == countDigits) {
	view->OutMemoryError();

	return EXIT_FAILURE;
  }

  if (consoleArgsValidator->CheckEnoughArgc(3u)) {
	std::unique_ptr<unsigned> temp = std::move(
		consoleArgsValidator->ValidateByIndex
			<unsigned>(2u, [](const char string[]) {
		  std::regex checkLetters(R"((\d+?))");
		  return std::regex_match(string, checkLetters);
		}));

	if (nullptr != temp && *countDigits != *temp) {
	  countDigits = std::move(temp);
	}
  }

  std::unique_ptr<task::sixth::LuckyTicketCounter> ltc
  	(new(std::nothrow) task::sixth::LuckyTicketCounter(*countDigits));
  if (nullptr == ltc) {
	view->OutMemoryError();

	return EXIT_FAILURE;
  }

  view->SetCounter(ltc->GetLuckyTicketsCount(luckyTicketType));
  view->OutCounter();

  return EXIT_SUCCESS;
}