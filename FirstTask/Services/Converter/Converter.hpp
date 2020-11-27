//
// Created by Александр Сафиюлин on 25.11.2020.
//

#ifndef HELPERS_CONVERTER_HPP
#define HELPERS_CONVERTER_HPP

#include <string>
#include <sstream>

#include "../Errors/ErrorHandler.hpp"

namespace task::helpers {
    template<class Type>
    class Converter {
        using value_type = Type;
    public:
        Converter()                 = delete;
        Converter(const Converter&) = delete;
        Converter(Converter&&)      = delete;

        static value_type ConvertString(const std::string& string) {
            std::stringstream stringStream;
            value_type result;

            stringStream << string;
            stringStream >> result;

            if (stringStream.fail()) {
                task::helpers::ErrorHandler::AssertAndExit
                        (task::helpers::Error::PARSE_DATA_ERROR);
            }

            return result;
        }

        ~Converter() = delete;
    };

}
#endif //HELPERS_CONVERTER_HPP
