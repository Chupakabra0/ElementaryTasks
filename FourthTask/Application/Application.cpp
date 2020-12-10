//
// Created by Александр Сафиюлин on 09.12.2020.
//

#include <algorithm>
#include <iostream>
#include <filesystem>

#include "Application.hpp"

#include "../Services/ConsoleArgsValidator/ConsoleArgsValidator.hpp"
#include "../Services/Errors/ErrorHandler/ErrorHandler.hpp"
#include "../Models/FileParserLineByLine/FileParserLineByLine.hpp"

task::fourth::Application::Application(const unsigned int argc, char **argv)
	: argc_(argc), argv_(argv) {}

task::fourth::Application &task::fourth::Application::GetInstance(const
																  unsigned argc,
																  char **argv) {
  static Application instance(argc, argv);
  return instance;
}

int task::fourth::Application::operator()() const {
  task::helpers::ErrorHandler errorHandler(task::helpers::ErrorCode::NO_ERROR);
  const std::string tempPath("temp.tmp");

  std::unique_ptr<task::helpers::ConsoleArgsValidator> consoleArgsValidator
	  (new(std::nothrow) task::helpers::ConsoleArgsValidator(this->argc_,
															 this->argv_));
  if (nullptr == consoleArgsValidator) {
	errorHandler.SetErrorCode(task::helpers::ErrorCode::MEMORY_OUT);
	errorHandler.OutError();

	return EXIT_FAILURE;
  }

  std::unique_ptr<std::string> filePath;
  std::unique_ptr<std::string> stringToFind;
  std::unique_ptr<std::string> stringToReplace;

  if (consoleArgsValidator->CheckEnoughArgc(4)) {
	filePath = consoleArgsValidator->ValidateByIndex<std::string>(1u);
	stringToFind = consoleArgsValidator->ValidateByIndex<std::string>(2u);
	stringToReplace = consoleArgsValidator->ValidateByIndex<std::string>(3u);

	if (nullptr == filePath || nullptr == stringToFind ||
		nullptr == stringToReplace) {
	  errorHandler.SetErrorCode(task::helpers::ErrorCode::MEMORY_OUT);
	  errorHandler.OutError();

	  return EXIT_FAILURE;
	}

	std::unique_ptr<task::fourth::CharFileParserLineByLine> parser
		(new(std::nothrow) task::fourth::CharFileParserLineByLine(*filePath));
	if (nullptr == parser) {
	  errorHandler.SetErrorCode(task::helpers::ErrorCode::MEMORY_OUT);
	  errorHandler.OutError();

	  return EXIT_FAILURE;
	}

	if (std::filesystem::space(std::filesystem::current_path()).free >
		std::filesystem::file_size(filePath->c_str())) {

	  std::fstream ofs(tempPath.c_str(), std::ios_base::trunc |
		  std::ios_base::out);

	  std::for_each(parser->begin(), parser->end(),
					[&stringToFind, &stringToReplace, &ofs](
						const std::string &
						string) {
					  if (string != *stringToFind) {
						ofs << string << std::endl;
					  } else {
						ofs << *stringToReplace << std::endl;
					  }
					});

	  ofs.close();
	  parser->CloseFile();

	  std::filesystem::remove(filePath->c_str());
	  std::filesystem::rename(tempPath.c_str(), filePath->c_str());

	  std::cout << "Done" << std::endl;
	} else {
	  std::cerr << "Not enough memory to do this operation" << std::endl;
	}
  } else if (consoleArgsValidator->CheckEnoughArgc(3)) {
	filePath = consoleArgsValidator->ValidateByIndex<std::string>(1u);
	stringToFind = consoleArgsValidator->ValidateByIndex<std::string>(2u);
	if (nullptr == filePath || nullptr == stringToFind) {
	  errorHandler.SetErrorCode(task::helpers::ErrorCode::PARSE_FAILED);
	  errorHandler.OutError();

	  return EXIT_FAILURE;
	}

	std::unique_ptr<task::fourth::CharFileParserLineByLine> parser
		(new(std::nothrow) task::fourth::CharFileParserLineByLine
			 (*filePath));
	if (nullptr == parser) {
	  errorHandler.SetErrorCode(task::helpers::ErrorCode::MEMORY_OUT);
	  errorHandler.OutError();

	  return EXIT_FAILURE;
	}

	auto count = 0u;
	std::for_each(parser->begin(), parser->end(),
				  [&count, &stringToFind](const std::string &string) {
					if (string != *stringToFind) {
					  return;
					}
					++count;
				  });

	std::cout << count;
  } else {
	std::cout << "Not enough args:" << std::endl
			  << "FourthTask.exe filePath stringToCount" << std::endl
			  << "FourthTask.exe filePath stringToFind stringToReplace" <<
			  std::endl;

	return EXIT_SUCCESS;
  }

  return EXIT_SUCCESS;
}