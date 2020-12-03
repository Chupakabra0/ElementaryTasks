//
// Created by Александр Сафиюлин on 26.11.2020.
//

#ifndef HELPERS_ERRORHANDLER_HPP
#define HELPERS_ERRORHANDLER_HPP

#include <iostream>

#include "ErrorCode.hpp"

namespace task::helpers {

    class ErrorHandler {
    public:
        ErrorHandler()                    = delete;
        ErrorHandler(const ErrorHandler&) = delete;
        ErrorHandler(ErrorHandler&&)      = delete;

        template<class Stream = std::basic_ostream<char>>
        static void Assert(Error code, Stream& stream = std::cerr) {
            stream << ToString(code) << std::endl;
        }

        static void Exit(int exitCode = EXIT_FAILURE) {
            exit(exitCode);
        }

        template<class Stream = std::basic_ostream<char>>
        static void AssertAndExit
            (Error code, Stream& stream = std::cerr, int exitCode = EXIT_FAILURE) {
            Assert(code);
            Exit(exitCode);
        }

        ~ErrorHandler() = default;

    private:

    };
}

#endif //HELPERS_ERRORHANDLER_HPP
