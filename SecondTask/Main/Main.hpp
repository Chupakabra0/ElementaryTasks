//
// Created by Александр Сафиюлин on 03.12.2020.
//

#ifndef SECONDTASK_MAIN_HPP
#define SECONDTASK_MAIN_HPP

#include <algorithm>
#include <iostream>
#include <string>
#include <regex>

#include "../Models/Envelope/Envelope.hpp"
#include "../ViewModels/ViewModel.hpp"
#include "../View/View.hpp"
#include "../Services/ConsoleInputValidator/ConsoleInputValidator.hpp"

namespace task::second
{
	class Main
	{
	public:
		Main() = default;

		Main(const Main&) = default;

		Main(Main&&) = default;

		int operator()() const
		{
			std::string flag;
			do
			{
				std::unique_ptr<
						task::helpers::ConsoleInputValidator> consoleValidator
						(new(std::nothrow) task::helpers::ConsoleInputValidator());
				if (nullptr == consoleValidator)
				{
					std::cerr << "Memory error" << std::endl;
				}

				auto positiveDouble = [](const char string[]) -> bool
				{
					const std::regex number(R"((^\d+?(\.\d+?$|$)))");
					return std::regex_match(string, number)
						   &&
						   std::string(string).find('-') == std::string::npos;
				};

				std::cout << "Creating first envelope." << std::endl
						  << "Enter height:" << std::endl;
				std::unique_ptr<double> firstHeight = std::move
						(consoleValidator->LoopInput<double>(positiveDouble));

				std::cout << "Enter width:" << std::endl;
				std::unique_ptr<double> firstWidth = std::move(
						consoleValidator->LoopInput<double>
								(positiveDouble));

				std::cout << "Creating second envelope." << std::endl
						  << "Enter height:" << std::endl;
				std::unique_ptr<double> secondHeight = std::move(
						consoleValidator->LoopInput<double>
								(positiveDouble));
				std::cout << "Enter width:" << std::endl;
				std::unique_ptr<double> secondWidth = std::move(
						consoleValidator->LoopInput<double>
								(positiveDouble));

				const task::second::Envelope firstEnvelope(*firstHeight,
														   *firstWidth);
				const task::second::Envelope secondEnvelope(*secondHeight,
															*secondWidth);

				std::unique_ptr<task::second::ViewModel> viewModel
						(new(std::nothrow) task::second::ViewModel(
								firstEnvelope,
								secondEnvelope));
				if (nullptr == viewModel)
				{
					std::cerr << "Memory error" << std::endl;
				}

				std::unique_ptr<task::second::View> view
						(new(std::nothrow) task::second::View(*viewModel));
				if (nullptr == view)
				{
					std::cerr << "Memory error" << std::endl;
				}

				view->Out();

				std::cout << "Continue? [y/Yes]:";
				std::cin >> flag;
				std::cin.ignore();
				std::transform(flag.begin(), flag.end(), flag.begin(), toupper);
			} while ("Y" == flag || "YES" == flag);

			return EXIT_SUCCESS;
		}

		~Main() = default;

	private:

	};
}

#endif //SECONDTASK_MAIN_HPP