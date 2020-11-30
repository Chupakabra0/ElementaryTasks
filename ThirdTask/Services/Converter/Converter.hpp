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
        using pointer    = value_type*;
    public:
        Converter()                 = delete;
        Converter(const Converter&) = delete;
        Converter(Converter&&)      = delete;

        static pointer ConvertString(const std::string& string, bool
        predicate(const char[]) = nullptr) {

            if (predicate && !predicate(string.c_str())) {
                return nullptr;
            }

            std::stringstream stringStream;
            NO_THROW_NEW(result, value_type());

            stringStream << string;
            stringStream >> *result;

            if (stringStream.fail()) {
                NO_THROW_DELETE(result);
                return nullptr;
            }

            return result;
        }

        ~Converter() = delete;
    };

    template<>
    class Converter<std::string> {
    public:
        static std::string* ConvertString(const std::string& string, bool
        predicate(const char[]) = nullptr) {
            if (predicate && !predicate(string.c_str())) {
                return nullptr;
            }
            return new std::string(string);
        }
    };
}
#endif //HELPERS_CONVERTER_HPP
