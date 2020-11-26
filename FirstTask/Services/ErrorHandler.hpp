//
// Created by Александр Сафиюлин on 26.11.2020.
//

#ifndef HELPERS_ERRORHANDLER_HPP
#define HELPERS_ERRORHANDLER_HPP

#include <iostream>

namespace task::helpers {
    class ErrorHandler {
    public:
        ErrorHandler()                    = default;
        ErrorHandler(const ErrorHandler&) = delete;
        ErrorHandler(ErrorHandler&&)      = delete;

        template<class Stream = std::basic_ostream<char>>
        static bool Assert(bool condition, const std::string& message, Stream&
        stream = std::cerr) {
            if (condition) {
                stream << message << std::endl;
            }
            // TIP: it's interesting, but seems to be quite useless sometimes
            return condition;
        }

        static void Exit(int code = EXIT_FAILURE) {
            exit(code);
        }

        template<class Stream = std::basic_ostream<char>>
        static void AssertAndExit(bool condition, const std::string& message,
                             Stream& stream = std::cerr, int code = EXIT_FAILURE) {
            if (Assert(condition, message, stream)) {
                Exit(code);
            }
        }

        ~ErrorHandler() = default;

    private:
        // TODO replace cerr, or make fields and remove static functions
    };
}

#endif //HELPERS_ERRORHANDLER_HPP
