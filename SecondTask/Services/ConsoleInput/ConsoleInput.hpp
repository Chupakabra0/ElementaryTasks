//
// Created by Александр Сафиюлин on 30.11.2020.
//

#ifndef SECONDTASK_CONSOLEINPUT_HPP
#define SECONDTASK_CONSOLEINPUT_HPP

#include <iostream>
#include <string>

#include "../Converter/Converter.hpp"

namespace task::helpers {
    class ConsoleInput {
    public:
        ConsoleInput()                        = default;
        ConsoleInput(const ConsoleInput&)     = default;
        ConsoleInput(ConsoleInput&&)          = default;

        template<class Type>
        Type* LoopInput(bool predicate(const char[]) = nullptr) {
            Type* data;
            std::string temp;
            do {
                std::cin >> temp;
                if (std::cin) {
                    data = task::helpers::Converter<Type>::ConvertString
                            (temp, predicate);
                    if (data) {
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
            return data;
        }

    private:

    };
}

#endif //SECONDTASK_CONSOLEINPUT_HPP
