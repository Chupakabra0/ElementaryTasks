#include <iostream>
#include <string>
#include <regex>

#include "Services/ConsoleInputValidator/ConsoleInputValidator.hpp"
#include "Services/StringCleaner/StringCleaner.hpp"
#include "Services/StringSpliter/StringSplitter.hpp"

int main() {

    NO_THROW_NEW(consoleInputValidator, task::helpers::ConsoleInputValidator());
    NO_THROW_NEW(stringCleaner, task::helpers::StringCleaner(' '));
    NO_THROW_NEW(stringSplitter, task::helpers::StringSplitter(','));

    auto* triangleString = consoleInputValidator->LoopInput<std::string>();
    *triangleString = stringCleaner->Clean(*triangleString);
    auto triangleParams = stringSplitter->Split(*triangleString);

    NO_THROW_DELETE(triangleString);
    NO_THROW_DELETE(stringSplitter);
    NO_THROW_DELETE(stringCleaner);
    NO_THROW_DELETE(consoleInputValidator);

    if (triangleParams.size() < 4) {
        task::helpers::ErrorHandler::Assert
        (task::helpers::Error::PARSE_DATA_ERROR);
    }
    else {
        auto isPositiveDouble = [](const char string[]) -> bool {
            const std::regex number(R"((^\d+?(\.\d+?$|$)))");
            return std::regex_match(string, number)
                   && std::string(string).find('-') == std::string::npos;
        };

        auto* triangleName =
                task::helpers::Converter<std::string>::ConvertString
                (triangleParams[0]);
        auto* firstSide =
                task::helpers::Converter<double>::ConvertString
                (triangleParams[1], isPositiveDouble);
        auto* secondSide =
                task::helpers::Converter<double>::ConvertString
                (triangleParams[2], isPositiveDouble);
        auto* thirdSide =
                task::helpers::Converter<double>::ConvertString
                (triangleParams[3], isPositiveDouble);

        if (!triangleName || !firstSide || !secondSide || !thirdSide) {
            task::helpers::ErrorHandler::Assert
                    (task::helpers::Error::PARSE_DATA_ERROR);
        }

        std::cout << "[" << *triangleName << "]" << " " << *firstSide << " "
        << *secondSide << " " << *thirdSide << std::endl;

        NO_THROW_DELETE(firstSide);
        NO_THROW_DELETE(secondSide);
        NO_THROW_DELETE(thirdSide);
        NO_THROW_DELETE(triangleName);
    }

    return EXIT_SUCCESS;
}