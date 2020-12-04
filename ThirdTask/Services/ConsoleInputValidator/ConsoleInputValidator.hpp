//
// Created by Александр Сафиюлин on 30.11.2020.
//

#ifndef SECONDTASK_CONSOLEINPUTVALIDATOR_HPP
#define SECONDTASK_CONSOLEINPUTVALIDATOR_HPP

#include <iostream>
#include <memory>
#include <string>
#include <algorithm>

#include "../Converter/Converter.hpp"

namespace task::helpers
{
	class ConsoleInputValidator
	{
	public:
		ConsoleInputValidator() = default;

		ConsoleInputValidator(const ConsoleInputValidator&) = default;

		ConsoleInputValidator(ConsoleInputValidator&&) = default;

		template<class Type>
		std::unique_ptr<Type> LoopInput(bool predicate(const char[]) = nullptr)
		{
			std::unique_ptr<Type> data;
			std::string temp;
			do
			{
				getline(std::cin, temp);
				if (std::cin)
				{
					data = std::move
							(task::helpers::Converter<Type>::ConvertString(temp, predicate));
					if (nullptr == data)
					{
						task::helpers::ErrorHandler::Assert
								(task::helpers::Error::PARSE_DATA_ERROR);
					}
					else
					{
						return data;
					}
				}

				std::cerr << std::endl <<  "Try again." << std::endl;
				std::cin.clear();
			} while (true);
		}

		template<>
		std::unique_ptr<std::string> LoopInput(bool predicate(const char[]))
		{
			std::string temp;
			do
			{
				getline(std::cin, temp);
				if (!std::cin || (nullptr != predicate && !predicate(temp.c_str())))
				{
					task::helpers::ErrorHandler::Assert
								(task::helpers::Error::PARSE_DATA_ERROR);
				}
				else {
					return std::make_unique<std::string>(temp);
				}

				std::cerr << std::endl <<  "Try again." << std::endl;
				std::cin.clear();
			} while (true);
		}

		template<class Type>
		std::unique_ptr<Type> Input(bool predicate(const char[]) = nullptr)
		{
			std::unique_ptr<Type> data;
			std::string temp;
			getline(std::cin, temp);
			if (std::cin)
			{
				data = task::helpers::Converter<Type>::ConvertString
						(temp, predicate);
			}
			if (!data)
			{
				task::helpers::ErrorHandler::AssertAndExit(
						task::helpers::Error::PARSE_DATA_ERROR);
			}
			return data;
		}

		template<>
		std::unique_ptr<std::string> Input(bool predicate(const char[]))
		{
			std::unique_ptr<std::string> data;
			std::string temp;
			getline(std::cin, temp);
			if (!std::cin || (nullptr != predicate && !predicate(temp.c_str())))
			{
				task::helpers::ErrorHandler::AssertAndExit(
						task::helpers::Error::PARSE_DATA_ERROR);
			}
			data = std::move(std::make_unique<std::string>(temp));
			return data;
		}

	private:

	};
}

#endif //SECONDTASK_CONSOLEINPUTVALIDATOR_HPP
