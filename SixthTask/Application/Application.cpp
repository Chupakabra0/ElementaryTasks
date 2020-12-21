//
// Created by Александр Сафиюлин on 11.12.2020.
//

#include <iostream>
#include <regex>

#include "Application.hpp"

#include <ConsoleArgsValidator/ConsoleArgsValidator.hpp>
#include <FileInputValidator/FileInputValidator.hpp>
#include <Errors/ErrorHandler/ErrorHandler.hpp>
#include <LuckyTicketCounter/LuckyTicketCounter.hpp>
#include <View.hpp>

task::sixth::Application::Application(const unsigned argc, const char **argv)
	: argc_(argc), argv_(argv) {}

task::sixth::Application &task::sixth::Application::GetInstance(const unsigned argc,
																const char **argv) {
  static Application instance(argc, argv);
  return instance;
}

int task::sixth::Application::operator()() const {
  helpers::ErrorHandler errorHandler(helpers::ErrorCode::NO_ERROR);

  std::unique_ptr<View<std::ostream>> view
	  (new(std::nothrow) View<std::ostream>(std::cout, errorHandler));
  if (nullptr == view) {
	errorHandler.SetErrorCode(helpers::ErrorCode::MEMORY_OUT);
	errorHandler.OutError("\n");

	return EXIT_FAILURE;
  }

  std::unique_ptr<helpers::ConsoleArgsValidator> consoleArgsValidator
	  (new(std::nothrow) helpers::ConsoleArgsValidator(this->argc_,
													   this->argv_));
  if (nullptr == consoleArgsValidator) {
	view->OutParseError();

	return EXIT_FAILURE;
  }

  if (!consoleArgsValidator->CheckEnoughArgc(2u)) {
	view->OutNotEnoughArgumentsMessage();

	return EXIT_SUCCESS;
  }

  const std::unique_ptr<std::string> filePath =
	  consoleArgsValidator->ValidateByIndex<std::string>(1u);
  if (nullptr == filePath) {
	view->OutParseError();

	return EXIT_FAILURE;
  }

  std::unique_ptr<helpers::FileInputValidator> fileInputValidator
	  (new(std::nothrow) helpers::FileInputValidator
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
  // C++14
  //std::transform(flag->begin(), flag->end(), flag->begin(), toupper);
  // C++20
  std::ranges::transform(*flag, flag->begin(), toupper);

  const auto luckyTicketType = FromString(*flag);
  if (LuckyTicketType::NONE == luckyTicketType) {
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
		  const std::regex checkLetters(R"((\d+?))");
		  return std::regex_match(string, checkLetters);
		}));

	if (nullptr != temp && *countDigits != *temp) {
	  countDigits = std::move(temp);
	}
  }

  const std::unique_ptr<LuckyTicketCounter> ltc
	  (new(std::nothrow) LuckyTicketCounter(*countDigits));
  if (nullptr == ltc) {
	view->OutMemoryError();

	return EXIT_FAILURE;
  }

  view->SetCounter(ltc->GetLuckyTicketsCount(luckyTicketType));
  view->OutCounter();

  return EXIT_SUCCESS;
}