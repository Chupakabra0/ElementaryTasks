//
// Created by Александр Сафиюлин on 25.11.2020.
//

#ifndef HELPERS_HELPERS_HPP
#define HELPERS_HELPERS_HPP

#include <string>
#include <sstream>

namespace task::helpers {
    template<class Type>
    Type ConvertString(const std::string& string);

    template<class Type>
    Type ConvertString(const std::string& string) {
            std::stringstream stringStream;
            Type result;

            stringStream << string;
            stringStream >> result;

            if (stringStream.fail()) {
                throw std::runtime_error("ConvertString: Bad input error...");
            }

            return result;
        }
    }
#endif //HELPERS_HELPERS_HPP
