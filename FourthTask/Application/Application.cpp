//
// Created by Александр Сафиюлин on 09.12.2020.
//

#include <algorithm>
#include <iostream>
#include <filesystem>

#include "Application.hpp"

#include <ConsoleArgsValidator/ConsoleArgsValidator.hpp>
#include <Errors/ErrorHandler/ErrorHandler.hpp>
#include <File/Reader/FileReader.hpp>
#include <File/Writter/FileWriter.hpp>
#include <DataFunctions/DataFunctions.hpp>
#include <View.hpp>

task::fourth::Application::Application(const unsigned int argc,
									   const char **argv)
	: argc_(argc), argv_(argv) {}

task::fourth::Application &task::fourth::Application::GetInstance(const
																  unsigned argc,
																  const char **argv) {
  static Application instance(argc, argv);
  return instance;
}

int task::fourth::Application::operator()() const {
  helpers::ErrorHandler errorHandler(helpers::ErrorCode::NO_ERROR);

  std::unique_ptr<View<std::ostream>> view(new(std::nothrow)
											   View<std::ostream>(std::cout,
																  errorHandler));
  if (nullptr == view) {
	errorHandler.SetErrorCode(helpers::ErrorCode::MEMORY_OUT);
	errorHandler.OutError();

	return EXIT_FAILURE;
  }

  std::unique_ptr<helpers::ConsoleArgsValidator> consoleArgsValidator
	  (new(std::nothrow) helpers::ConsoleArgsValidator(this->argc_,
													   this->argv_));
  if (nullptr == consoleArgsValidator) {
	view->OutMemoryError();

	return EXIT_FAILURE;
  }

  if (!consoleArgsValidator->CheckEnoughArgc(3u)) {
	view->OutInstructionsMessage();

	return EXIT_SUCCESS;
  }

  auto filePath = consoleArgsValidator->ValidateByIndex<std::string>(1u);
  auto mainString = consoleArgsValidator->ValidateByIndex<std::string>(2u);

  std::unique_ptr<fourth::FileReader> fileReader
	  (new(std::nothrow) fourth::FileReader(std::filesystem::path(*filePath)));

  if (nullptr == fileReader) {
	view->OutMemoryError();

	return EXIT_FAILURE;
  }

  auto fileData = fileReader->GetFileStrings();

  if (fileData.empty()) {
    view->OutNotDoneMessage();

	return EXIT_SUCCESS;
  }

  if (consoleArgsValidator->CheckEnoughArgc(4u)) {
	const std::string tempPath("temp.tmp");
	auto subString = consoleArgsValidator->ValidateByIndex<std::string>(3u);

	std::unique_ptr<fourth::FileWriter> fileWriter
		(new(std::nothrow) fourth::FileWriter(tempPath));

	if (nullptr == fileWriter) {
	  view->OutMemoryError();

	  return EXIT_FAILURE;
	}

	if (std::filesystem::space(std::filesystem::current_path()).free <=
		std::filesystem::file_size(*filePath)) {
	  view->OutNotDoneMessage();

	  return EXIT_SUCCESS;
	}

	DataFunctions::ReplaceEq(fileData.begin(), fileData.end(),
							 *mainString, *subString);

	if (!fileWriter->WriteStrings(fileData)) {
	  view->OutNotDoneMessage();

	  return EXIT_SUCCESS;
	}

	fileReader->Close();
	fileWriter->Close();

	if (std::filesystem::exists(*filePath)) {
	  std::filesystem::remove(*filePath);
	}

	if (std::filesystem::exists(tempPath)) {
	  std::filesystem::rename(tempPath, *filePath);
	}

  } else {

	fileReader->Close();
    auto count = DataFunctions::CountEq(fileData.begin(), fileData.end(),
										*mainString);

	view->OutFileWordCount(*mainString, count);
  }

  view->OutDoneMessage();

  return EXIT_SUCCESS;
}