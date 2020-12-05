#include <algorithm>
#include <iostream>

#include "Services/ConsoleArgsValidator/ConsoleArgsValidator.hpp"
#include "Models/FileParserLineByLine/FileParserLineByLine.hpp"

int main(int argc, char** argv)
{
	std::unique_ptr<task::helpers::ConsoleArgsValidator> consoleArgsValidator
			(new(std::nothrow) task::helpers::ConsoleArgsValidator(argc, argv));
	if (nullptr == consoleArgsValidator) {
		std::cerr << "Memory error" << std::endl;

		return EXIT_FAILURE;
	}

	std::unique_ptr<std::string> filePath;
	std::unique_ptr<std::string> stringToCount;
	std::unique_ptr<std::string> stringToReplace;

	if (consoleArgsValidator->CheckEnoughArgc(4)) {
		filePath = std::move(consoleArgsValidator->ValidateByIndex<std
			::string>(1u));
		stringToCount = std::move(consoleArgsValidator->ValidateByIndex<std
			::string>(2u));
		stringToReplace = std::move(consoleArgsValidator->ValidateByIndex<std
			::string>(3u));

		if (nullptr == filePath || nullptr == stringToCount || nullptr == stringToReplace) {
			std::cerr << "Parse error" << std::endl;

			return EXIT_FAILURE;
		}

		std::unique_ptr<task::fourth::FileParserLineByLine> parser
				(new(std::nothrow) task::fourth::FileParserLineByLine
						 (*filePath));
		if (nullptr == parser) {
			std::cerr << "Memory error" << std::endl;

			return EXIT_FAILURE;
		}

		std::ifstream ifs("input.txt");

		// TODO string replace
	}
	else if (consoleArgsValidator->CheckEnoughArgc(3)) {
		filePath = std::move(consoleArgsValidator->ValidateByIndex<std
				::string>(1u));
		stringToCount = std::move(consoleArgsValidator->ValidateByIndex<std
				::string>(2u));
		if (nullptr == filePath || nullptr == stringToCount) {
			std::cerr << "Parse error" << std::endl;

			return EXIT_FAILURE;
		}

		std::unique_ptr<task::fourth::FileParserLineByLine> parser
				(new(std::nothrow) task::fourth::FileParserLineByLine
				(*filePath));
		if (nullptr == parser) {
			std::cerr << "Memory error" << std::endl;

			return EXIT_FAILURE;
		}

		auto count = 0u;
		std::for_each(parser->begin(), parser->end(),
		  [&count, &stringToCount](const std::string& string) {
			for (auto i = string.find(*stringToCount); i != std::string::npos;
				i = string.find
						(*stringToCount, i + stringToCount->size())) {
				// TODO: ask about "abababab"
				//		(*stringToCount, i + 1))
				++count;
			}
		});

		std::cout << count;
	}
	else {
		std::cout << "Not enough args:" << std::endl
		<< "Fourth.exe filePath stringToCount" << std::endl;

		return EXIT_SUCCESS;
	}

	return EXIT_SUCCESS;
}
