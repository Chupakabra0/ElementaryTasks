//
// Created by Александр Сафиюлин on 05.12.2020.
//

#ifndef FOURTHTASK_MAIN_HPP
#define FOURTHTASK_MAIN_HPP

#include <iostream>
#include <regex>

#include "Models/Prescription.hpp"
#include "Services/ConsoleArgsValidator/ConsoleArgsValidator.hpp"
#include "View/View.hpp"

namespace task::fifth {
	class Main {
	public:
		Main() = default;
		Main(const Main&) = default;
		Main(Main&&) = default;

		int operator()(const unsigned argc, char** argv) const {
			std::unique_ptr<task::helpers::ConsoleArgsValidator> consoleArgsValidator
					(new(std::nothrow) task::helpers::ConsoleArgsValidator(argc, argv));
			if (nullptr == consoleArgsValidator)
			{
				std::cerr << "Memory error" << std::endl;

				return EXIT_FAILURE;
			}

			std::unique_ptr<long long> number;

			if (consoleArgsValidator->CheckEnoughArgc(2))
			{
				number = consoleArgsValidator->ValidateByIndex<long long>
						(1u, [](const char string[]) -> bool
						{
							std::regex regex(R"((^|^-)(\d+?)$)");
							return std::regex_match(string, regex);
						});

				if (nullptr == number)
				{
					std::cerr << "Parse error" << std::endl;

					return EXIT_FAILURE;
				}
			}
			else
			{
				std::cout << "Args not enough" << std::endl
						  << "FourthTask.exe number" << std::endl;

				return EXIT_SUCCESS;
			}

			std::unique_ptr<View> view(new(std::nothrow) View(*number));
			if (nullptr == view) {
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

#endif //FOURTHTASK_MAIN_HPP
