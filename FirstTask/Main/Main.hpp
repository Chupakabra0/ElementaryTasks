//
// Created by Александр Сафиюлин on 04.12.2020.
//

#ifndef FIRSTTASK_MAIN_HPP
#define FIRSTTASK_MAIN_HPP

#include <iostream>
#include <regex>

#include "../Models/Board/BoardFactory.hpp"
#include "../ViewModels/ViewModel.hpp"
#include "../View/View.hpp"
#include "../Services/ConsoleArgsValidator/ConsoleArgsValidator.hpp"

namespace task::first
{
	class Main
	{
	public:
		Main() = default;

		Main(const Main&) = default;

		Main(Main&&) = default;

		int operator()(const unsigned argc, char* argv[])
		{
			std::unique_ptr<unsigned short> rowsCount, columnsCount;
			std::unique_ptr<
					task::helpers::ConsoleArgsValidator> consoleArgsValidator
					(new(std::nothrow) task::helpers::ConsoleArgsValidator(argc,
																		   argv));
			if (nullptr == consoleArgsValidator)
			{
				std::cerr << "Memory error" << std::endl;

				return EXIT_FAILURE;
			}

			const auto checkLetters = [](const char string[]) -> bool
			{
				const std::regex lettersCheck(R"((\d+?))");
				return std::regex_match(string, lettersCheck);
			};

			if (consoleArgsValidator->CheckEnoughArgc(3))
			{
				rowsCount = std::move(
						consoleArgsValidator->ValidateByIndex<unsigned
						short>(1, checkLetters));
				if (nullptr == rowsCount)
				{
					std::cerr << "Parse data error" << std::endl;

					return EXIT_FAILURE;
				}

				columnsCount = std::move(
						consoleArgsValidator->ValidateByIndex<unsigned
						short>(2, checkLetters));
				if (nullptr == columnsCount)
				{
					std::cerr << "Parse data error" << std::endl;

					return EXIT_FAILURE;
				}
			}
			else
			{
				std::cout << "Arguments error..." << std::endl;
				std::cout << "FirstTask.exe rowsCount columnsCount"
						  << std::endl;

				return EXIT_SUCCESS;
			}

			std::unique_ptr<task::first::BoardFactory> boardFactory
					(new(std::nothrow) task::first::BoardFactory('*', ' '));
			if (nullptr == boardFactory)
			{
				std::cerr << "Memory error" << std::endl;

				return EXIT_FAILURE;
			}

			std::unique_ptr<task::first::Board> board
					(std::move(boardFactory->CreateBoard(*rowsCount,
														 *columnsCount)));
			if (nullptr == board)
			{
				std::cerr << "Memory error" << std::endl;

				return EXIT_FAILURE;
			}

			std::unique_ptr<task::first::ViewModel> viewModel
					(new(std::nothrow) task::first::ViewModel(*board));
			if (nullptr == viewModel)
			{
				std::cerr << "Memory error" << std::endl;

				return EXIT_FAILURE;
			}

			std::unique_ptr<task::first::View> view
					(new(std::nothrow) task::first::View(*viewModel));
			if (nullptr == view)
			{
				std::cerr << "Memory error" << std::endl;

				return EXIT_FAILURE;
			}

			view->Out();

			return EXIT_SUCCESS;
		}

		~Main() = default;

	private:

	};
}

#endif //FIRSTTASK_MAIN_HPP
