//
// Created by Александр Сафиюлин on 04.12.2020.
//

#ifndef THIRDTASK_MAIN_HPP
#define THIRDTASK_MAIN_HPP

#include <iostream>
#include <string>
#include <regex>
#include <set>

#include "Services/ConsoleInputValidator/ConsoleInputValidator.hpp"
#include "Services/StringCleaner/StringCleaner.hpp"
#include "Services/StringSpliter/StringSplitter.hpp"

#include "Models/Triangle/Triangle.hpp"
#include "../ViewModel/ViewModel.hpp"
#include "../View/View.hpp"

namespace task::third {
	class Main {
	public:
		Main() = default;
		Main(const Main&) = default;
		Main(Main&&) = default;

		int operator()() {
			std::string flag;
			std::unique_ptr<task::third::ViewModel> vm(new(std::nothrow)
				task::third::ViewModel
				(std::multiset<task::third::Triangle, std::greater<>>()));
			if (nullptr == vm)
			{
				std::cerr << "Memory error" << std::endl;

				return EXIT_FAILURE;
			}

			std::unique_ptr<task::third::View>
			        view(new(std::nothrow) task::third::View(*vm));
			if (nullptr == view)
			{
				std::cerr << "Memory error" << std::endl;

				return EXIT_FAILURE;
			}

			do
			{
				std::unique_ptr<task::helpers::ConsoleInputValidator>
						consoleInputValidator(new(std::nothrow)
													  task::helpers::ConsoleInputValidator());
				if (nullptr == consoleInputValidator)
				{
					std::cerr << "Memory error" << std::endl;

					return EXIT_FAILURE;
				}

				std::unique_ptr<task::helpers::StringCleaner> stringCleaner(new
				(std::nothrow) task::helpers::StringCleaner(' '));
				if (nullptr == stringCleaner)
				{
					std::cerr << "Memory error" << std::endl;

					return EXIT_FAILURE;
				}

				std::unique_ptr<task::helpers::StringSplitter> stringSplitter(new
				(std::nothrow) task::helpers::StringSplitter(','));
				if (nullptr == stringSplitter)
				{
					std::cerr << "Memory error" << std::endl;

					return EXIT_FAILURE;
				}

				std::cout << "Enter a new triangle in format:" << std::endl
				<< "Name, FirstSide, SecondSide, ThirdSide" << std::endl;

				std::unique_ptr<std::string> triangleString = std::move
						(consoleInputValidator->LoopInput<std::string>());
				if (nullptr == triangleString)
				{
					std::cerr << "Memory error" << std::endl;

					return EXIT_FAILURE;
				}

				*triangleString = stringCleaner->Clean(*triangleString);
				const auto triangleParams = stringSplitter->Split(*triangleString);

				// TIP: maybe release memory

				if (triangleParams.size() < 4)
				{
					std::cerr << "Parse data error" << std::endl;
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
						std::cerr << "Parse data error" << std::endl;
					}
					else
					{
						std::unique_ptr<task::third::Triangle> triangle
								(task::third::Triangle::CreateUniquePtrTriangle
										 (*triangleName, *firstSide, *secondSide, *thirdSide));

						if (nullptr == triangle) {
							std::cerr << "Triangle creation error" << std::endl;
						}
						else {
							vm->AddToMultiset(*triangle);
						}

						view->SetVM(*vm);
						view->Out();
					}

					std::cout << std::endl << "Continue? [y/Yes]:";
					std::cin >> flag;
					std::cin.ignore();
					std::transform(flag.begin(), flag.end(), flag.begin(), toupper);
				}
			} while ("Y" == flag || "YES" == flag);

			return EXIT_SUCCESS;
		}

		~Main() = default;
	private:

	};
}

#endif //THIRDTASK_MAIN_HPP
