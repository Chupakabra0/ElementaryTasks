#include <iostream>
#include <string>
#include <regex>

#include "Services/ConsoleInputValidator/ConsoleInputValidator.hpp"
#include "Services/StringCleaner/StringCleaner.hpp"
#include "Services/StringSpliter/StringSplitter.hpp"

int main()
{
	std::string flag;
	do
	{
		std::unique_ptr<task::helpers::ConsoleInputValidator>
				consoleInputValidator(new(std::nothrow)
											  task::helpers::ConsoleInputValidator());
		if (nullptr == consoleInputValidator)
		{
			task::helpers::ErrorHandler::AssertAndExit
					(task::helpers::Error::MEMORY_LACK_ERROR);
		}

		std::unique_ptr<task::helpers::StringCleaner> stringCleaner(new
		(std::nothrow) task::helpers::StringCleaner(' '));
		if (nullptr == stringCleaner)
		{
			task::helpers::ErrorHandler::AssertAndExit
					(task::helpers::Error::MEMORY_LACK_ERROR);
		}

		std::unique_ptr<task::helpers::StringSplitter> stringSplitter(new
		(std::nothrow) task::helpers::StringSplitter(','));
		if (nullptr == stringSplitter)
		{
			task::helpers::ErrorHandler::AssertAndExit
					(task::helpers::Error::MEMORY_LACK_ERROR);
		}

		std::unique_ptr<std::string> triangleString = std::move
				(consoleInputValidator->LoopInput<std::string>());
		if (nullptr == triangleString)
		{
			task::helpers::ErrorHandler::AssertAndExit
					(task::helpers::Error::MEMORY_LACK_ERROR);
		}

		*triangleString = stringCleaner->Clean(*triangleString);
		const auto triangleParams = stringSplitter->Split(*triangleString);

		// TIP: maybe release memory

		if (triangleParams.size() < 4)
		{
			task::helpers::ErrorHandler::Assert
					(task::helpers::Error::PARSE_DATA_ERROR);
		}
		else
		{
			auto isPositiveDouble = [](const char string[]) -> bool
			{
				const std::regex number(R"((^\d+?(\.\d+?$|$)))");
				return std::regex_match(string, number)
					   && std::string(string).find('-') == std::string::npos;
			};

			std::unique_ptr<std::string> triangleName =
					std::move(task::helpers::Converter<std::string>::
							  ConvertString(triangleParams[0]));
			std::unique_ptr<double> firstSide =
					std::move(task::helpers::Converter<double>::ConvertString
									  (triangleParams[1], isPositiveDouble));
			std::unique_ptr<double> secondSide =
					std::move(task::helpers::Converter<double>::ConvertString
									  (triangleParams[2], isPositiveDouble));
			std::unique_ptr<double> thirdSide =
					std::move(task::helpers::Converter<double>::ConvertString
									  (triangleParams[3], isPositiveDouble));

			if (nullptr == triangleName || nullptr == firstSide ||
				nullptr == secondSide || nullptr == thirdSide)
			{
				task::helpers::ErrorHandler::Assert
						(task::helpers::Error::PARSE_DATA_ERROR);
			}
			else
			{
				std::cout << "[" << *triangleName << "]" << " " << *firstSide
						  << " "
						  << *secondSide << " " << *thirdSide << std::endl;
			}

			std::cout << std::endl << "Continue? [y/Yes]:";
			std::cin >> flag;
			std::cin.ignore();
			std::transform(flag.begin(), flag.end(), flag.begin(), toupper);
		}
	} while ("Y" == flag || "YES" == flag);

	return EXIT_SUCCESS;
}