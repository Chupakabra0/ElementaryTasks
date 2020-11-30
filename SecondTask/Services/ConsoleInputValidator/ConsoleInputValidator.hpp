//
// Created by Александр Сафиюлин on 30.11.2020.
//

#ifndef SECONDTASK_CONSOLEINPUTVALIDATOR_HPP
#define SECONDTASK_CONSOLEINPUTVALIDATOR_HPP

#include <iostream>
#include <string>

#include "../Converter/Converter.hpp"

namespace task::helpers {
    class ConsoleInputValidator {
    public:
        ConsoleInputValidator()                             = default;
        ConsoleInputValidator(const ConsoleInputValidator&) = default;
        ConsoleInputValidator(ConsoleInputValidator&&)      = default;

        template<class Type>
        Type* LoopInput(bool predicate(const char[]) = nullptr) {
            Type* data;
            std::string temp;
            do {
                std::cin >> temp;
                if (std::cin) {
                    data = task::helpers::Converter<Type>::ConvertString
                            (temp, predicate);
                    if (!data) {
                        task::helpers::ErrorHandler::Assert
                                (task::helpers::Error::PARSE_DATA_ERROR);
                    }
                    else {
                        return data;
                    }
                }
                std::cerr << "Try again." << std::endl;
                std::cin.clear();
            } while (true);
        }

        template<class Type>
        Type* Input(bool predicate(const std::string&) = nullptr) {
            Type* data;
            std::string temp;
            std::cin >> temp;
            if (std::cin) {
                data = task::helpers::Converter<Type>::ConvertString
                        (temp, predicate);
            }
            if (!data) {
                task::helpers::ErrorHandler::AssertAndExit(task::helpers::Error::PARSE_DATA_ERROR);
            }
            return data;
        }

    private:

    };
}

#endif //SECONDTASK_CONSOLEINPUTVALIDATOR_HPP
