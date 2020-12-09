#include <iostream>
#include <regex>

#include "Services/ConsoleArgsValidator/ConsoleArgsValidator.hpp"
#include "Services/FileInputValidator/FileInputValidator.hpp"

#include "Models/LuckyTicketCounter/LuckyTicketCounter.hpp"

int main(int argc, char* argv[])
{
	std::unique_ptr<task::helpers::ConsoleArgsValidator> consoleArgsValidator
			(new(std::nothrow) task::helpers::ConsoleArgsValidator(argc, argv));
	if (nullptr == consoleArgsValidator)
	{
		std::cerr << "Memory error" << std::endl;

		return EXIT_FAILURE;
	}

	if (!consoleArgsValidator->CheckEnoughArgc(2u))
	{
		std::cout << "Not enough args" << std::endl
				  << "SixthTask.exe filePath" << std::endl;

		return EXIT_SUCCESS;
	}

	std::unique_ptr<std::string> filePath = std::move
			(consoleArgsValidator->ValidateByIndex<std::string>(1u));
	if (nullptr == filePath)
	{
		std::cerr << "Memory error" << std::endl;

		return EXIT_FAILURE;
	}

	std::unique_ptr<task::helpers::FileInputValidator> fileInputValidator(new
																				  (std::nothrow) task::helpers::FileInputValidator(
			std::filesystem::path
					(*filePath)));
	if (nullptr == fileInputValidator)
	{
		std::cerr << "Memory error" << std::endl;

		return EXIT_FAILURE;
	}
	if (!fileInputValidator->IsFileValid())
	{
		std::cerr << "Path invalid" << std::endl;

		return EXIT_FAILURE;
	}

	std::unique_ptr<std::string> flag = std::move
			(fileInputValidator->ValidLine());
	if (nullptr == flag)
	{
		std::cerr << "Parse error" << std::endl;

		return EXIT_FAILURE;
	}
	std::transform(flag->begin(), flag->end(), flag->begin(), toupper);

	// TODO: Piter and Moscow check
	auto luckyTicketType = task::sixth::FromString(*flag);
	if (task::sixth::LuckyTicketType::NONE == luckyTicketType)
	{
		std::cerr << "Ticket type error" << std::endl;

		return EXIT_FAILURE;
	}

	std::unique_ptr<unsigned> countDigits(new(std::nothrow) unsigned(3u));
	if (nullptr == countDigits)
	{
		std::cerr << "Memory error" << std::endl;

		return EXIT_FAILURE;
	}

	if (consoleArgsValidator->CheckEnoughArgc(3u))
	{
		std::unique_ptr<unsigned> temp = std::move(
				consoleArgsValidator->ValidateByIndex
						<unsigned>(2u, [](const char string[])
				{
					std::regex checkLetters(R"((\d+?))");
					return std::regex_match(string, checkLetters);
				}));

		// TODO: ask about zero check
		if (nullptr != temp && *countDigits != *temp)
		{
			countDigits = std::move(temp);
		}
	}

	std::unique_ptr<task::sixth::LuckyTicketCounter> ltc(new(std::nothrow)
																 task::sixth::LuckyTicketCounter(
			*countDigits));
	if (nullptr == ltc)
	{
		std::cerr << "Memory error" << std::endl;

		return EXIT_FAILURE;
	}
	
	std::cout << ltc->GetLuckyTicketsCount(luckyTicketType) << std::endl;

//	std::cout << "MOSCOW: " << ltc->GetLuckyTicketsCount
//	(task::sixth::LuckyTicketType::MOSCOW) <<
//	std::endl << "PITER: " << ltc->GetLuckyTicketsCount
//	(task::sixth::LuckyTicketType::PITER) << std::endl;

	return EXIT_SUCCESS;
}
