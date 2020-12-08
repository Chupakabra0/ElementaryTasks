#include <algorithm>
#include <iostream>
#include <filesystem>

#include "Services/ConsoleArgsValidator/ConsoleArgsValidator.hpp"
#include "Models/FileParserLineByLine/FileParserLineByLine.hpp"

int main(int argc, char** argv)
{
	std::unique_ptr<task::helpers::ConsoleArgsValidator> consoleArgsValidator
			(new(std::nothrow) task::helpers::ConsoleArgsValidator(argc, argv));
	if (nullptr == consoleArgsValidator)
	{
		std::cerr << "Memory error" << std::endl;

		return EXIT_FAILURE;
	}

	std::unique_ptr<std::string> filePath;
	std::unique_ptr<std::string> stringToFind;
	std::unique_ptr<std::string> stringToReplace;

	if (consoleArgsValidator->CheckEnoughArgc(4))
	{
		filePath = std::move(consoleArgsValidator->ValidateByIndex<std
		::string>(1u));
		stringToFind = std::move(consoleArgsValidator->ValidateByIndex<std
		::string>(2u));
		stringToReplace = std::move(consoleArgsValidator->ValidateByIndex<std
		::string>(3u));

		if (nullptr == filePath || nullptr == stringToFind ||
			nullptr == stringToReplace)
		{
			std::cerr << "Parse error" << std::endl;

			return EXIT_FAILURE;
		}

		std::unique_ptr<task::fourth::FileParserLineByLine> parser
				(new(std::nothrow) task::fourth::FileParserLineByLine
						 (*filePath));
		if (nullptr == parser)
		{
			std::cerr << "Memory error" << std::endl;

			return EXIT_FAILURE;
		}

		if (std::filesystem::space(std::filesystem::current_path()).free >
			std::filesystem::file_size(filePath->c_str()))
		{

			std::fstream ofs("temp.tmp", std::ios_base::trunc |
			std::ios_base::out);

			std::for_each(parser->begin(), parser->end(),
						  [&stringToFind, &stringToReplace, &ofs](
								  const std::string&
								  string)
						  {
							  if (string != *stringToFind)
							  {
								  ofs << string << std::endl;
							  }
							  else
							  {
								  ofs << *stringToReplace << std::endl;
							  }
						  });

			ofs.close();
			parser->Close();

			std::filesystem::remove(filePath->c_str());
			std::filesystem::rename("temp.tmp", filePath->c_str());

			std::cout << "Done" << std::endl;
		}
		else {
			std::cerr << "Not enough memory to do this operation" << std::endl;
		}
	}
	else if (consoleArgsValidator->CheckEnoughArgc(3))
	{
		filePath = std::move(consoleArgsValidator->ValidateByIndex<std
		::string>(1u));
		stringToFind = std::move(consoleArgsValidator->ValidateByIndex<std
		::string>(2u));
		if (nullptr == filePath || nullptr == stringToFind)
		{
			std::cerr << "Parse error" << std::endl;

			return EXIT_FAILURE;
		}

		std::unique_ptr<task::fourth::FileParserLineByLine> parser
				(new(std::nothrow) task::fourth::FileParserLineByLine
						 (*filePath));
		if (nullptr == parser)
		{
			std::cerr << "Memory error" << std::endl;

			return EXIT_FAILURE;
		}

		auto count = 0u;
		std::for_each(parser->begin(), parser->end(),
					  [&count, &stringToFind](const std::string& string)
					  {
						  if (string != *stringToFind)
						  {
							  return;
						  }
						  ++count;
					  });

		std::cout << count;
	}
	else
	{
		std::cout << "Not enough args:" << std::endl
				<< "Fourth.exe filePath stringToCount" << std::endl
				<< "Fourth.exe filePath stringToFind stringToReplace" <<
				std::endl;

		return EXIT_SUCCESS;
	}

	return EXIT_SUCCESS;
}
