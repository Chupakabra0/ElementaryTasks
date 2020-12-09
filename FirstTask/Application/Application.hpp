//
// Created by Александр Сафиюлин on 04.12.2020.
//

#pragma once

#ifndef FIRSTTASK_APPLICATION_HPP
#define FIRSTTASK_APPLICATION_HPP

#include <iostream>
#include <regex>

#include "../Models/Board/BoardCreator.hpp"
#include "../ViewModels/ViewModel.hpp"
#include "../View/View.hpp"
#include "../Services/ConsoleArgsValidator/ConsoleArgsValidator.hpp"

namespace task::first
{
	class Application
	{
	public:
		Application() = delete;

		Application(const Application&) = delete;

		Application(Application&&) noexcept = delete;

		Application& operator=(const Application&) = delete;

		Application& operator=(Application&&) = delete;

		static Application& GetInstance(const unsigned argc, char** argv)
		{
			static Application instance(argc, argv);
			return instance;
		}

		int operator()()
		{
			std::unique_ptr<unsigned short> rowsCount, columnsCount;
			std::unique_ptr<
					task::helpers::ConsoleArgsValidator> consoleArgsValidator
					(new(std::nothrow) task::helpers::ConsoleArgsValidator
							 (this->argc_, this->argv_));
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
				rowsCount = consoleArgsValidator->ValidateByIndex<unsigned
						short>(1, checkLetters);
				if (nullptr == rowsCount)
				{
					std::cerr << "Parse data error" << std::endl;

					return EXIT_FAILURE;
				}

				columnsCount = consoleArgsValidator->ValidateByIndex<unsigned
						short>(2, checkLetters);
				if (nullptr == columnsCount)
				{
					std::cerr << "Parse data error" << std::endl;

					return EXIT_FAILURE;
				}
			}
			else
			{
				std::cout << "Arguments error..." << std::endl
				<< "FirstTask.exe rowsCount columnsCount" << std::endl;

				return EXIT_SUCCESS;
			}

			std::unique_ptr<task::first::BoardCreator<char>> boardFactory
					(new(std::nothrow) task::first::BoardCreator('*', ' '));
			if (nullptr == boardFactory)
			{
				std::cerr << "Memory error" << std::endl;

				return EXIT_FAILURE;
			}

			std::unique_ptr<task::first::Board<char>> board
					= boardFactory->CreateBoard(*rowsCount, *columnsCount);
			if (nullptr == board)
			{
				std::cerr << "Memory error" << std::endl;

				return EXIT_FAILURE;
			}

			std::unique_ptr<task::first::ViewModel<char>> viewModel
					(new(std::nothrow) task::first::ViewModel(*board));
			if (nullptr == viewModel)
			{
				std::cerr << "Memory error" << std::endl;

				return EXIT_FAILURE;
			}

			std::unique_ptr<task::first::View<char>> view
					(new(std::nothrow) task::first::View(*viewModel));
			if (nullptr == view)
			{
				std::cerr << "Memory error" << std::endl;

				return EXIT_FAILURE;
			}

			view->Out();

			return EXIT_SUCCESS;
		}

		~Application() = default;

	private:

		explicit Application(const unsigned argc, char** argv)
				: argc_(argc), argv_(argv)
		{}

		unsigned argc_;
		char** argv_;
	};
}

#endif //FIRSTTASK_APPLICATION_HPP
