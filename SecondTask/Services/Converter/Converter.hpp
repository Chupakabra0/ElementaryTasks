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
    public:
        Converter()                 = delete;
        Converter(const Converter&) = delete;
        Converter(Converter&&)      = delete;

        static std::unique_ptr<Type> ConvertString(const std::string& string,
                                        bool predicate(const char[])) {

            if (predicate && !predicate(string.c_str())) {
                return nullptr;
            }

            std::stringstream stringStream;
            std::unique_ptr<Type> result(new(std::nothrow) Type());
            if (nullptr == result) {
                return nullptr;
            }

            stringStream << string;
            stringStream >> *result;

            if (stringStream.fail()) {
                return nullptr;
            }

            return result;
        }

        ~Converter() = delete;
    };

}
#endif //HELPERS_CONVERTER_HPP
