//
// Created by Александр Сафиюлин on 25.11.2020.
//

#ifndef HELPERS_CONVERTER_HPP
#define HELPERS_CONVERTER_HPP

#include <string>
#include <sstream>

#include "ErrorHandler.hpp"

namespace task::helpers {
    template<class Type>
    class Converter {
        using value_type = Type;
    public:
        Converter() = delete;
        Converter(const Converter&) = delete;
        Converter(Converter&&) = delete;

        static value_type ConvertString(const std::string &string) {
            std::stringstream stringStream;
            value_type result;

            stringStream << string;
            stringStream >> result;

            task::helpers::ErrorHandler::AssertAndExit(stringStream.fail(),
                                                       "Convert error...");

            return result;
        }

        ~Converter() = delete;
    };

}
#endif //HELPERS_CONVERTER_HPP
