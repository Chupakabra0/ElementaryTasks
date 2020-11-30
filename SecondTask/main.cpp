#include <algorithm>
#include <iostream>
#include <string>
#include <regex>

#include "Models/Envelope/Envelope.hpp"
#include "ViewModels/ViewModel.hpp"
#include "View/View.hpp"
#include "Services/Converter/Converter.hpp"
#include "Services/ConsoleInputValidator/ConsoleInputValidator.hpp"

int main() {
    std::string flag;
    do {
        NO_THROW_NEW(firstHeight, double());
        NO_THROW_NEW(firstWidth, double());
        NO_THROW_NEW(secondHeight, double());
        NO_THROW_NEW(secondWidth, double());

        NO_THROW_NEW(consoleValidator, task::helpers::ConsoleInputValidator());

        auto positive = [](const char string[]) -> bool {
            const std::regex number(R"((^\d+?(\.\d+?$|$)))");
            return std::regex_match(string, number)
                && std::string(string).find('-') == std::string::npos;
        };

        std::cout << "Creating first envelope." << std::endl << "Enter height:" << std::endl;
        firstHeight = consoleValidator->LoopInput<double>(positive);
        std::cout << "Enter width:" << std::endl;
        firstWidth = consoleValidator->LoopInput<double>(positive);

        std::cout << "Creating second envelope." << std::endl << "Enter height:" << std::endl;
        secondHeight = consoleValidator->LoopInput<double>(positive);
        std::cout << "Enter width:" << std::endl;
        secondWidth = consoleValidator->LoopInput<double>(positive);

        const task::second::Envelope firstEnvelope(*firstHeight, *firstWidth);
        const task::second::Envelope secondEnvelope(*secondHeight,
                                                    *secondWidth);

        NO_THROW_NEW(viewModel, task::second::ViewModel(firstEnvelope,
                                                    secondEnvelope));
        NO_THROW_NEW(view, task::second::View(*viewModel));

        view->Out();

        NO_THROW_DELETE(view);
        NO_THROW_DELETE(viewModel);
        NO_THROW_DELETE(consoleValidator);
        NO_THROW_DELETE(secondWidth);
        NO_THROW_DELETE(secondHeight);
        NO_THROW_DELETE(firstHeight);
        NO_THROW_DELETE(firstWidth);

        std::cout << "Continue? [y/Yes]:";
        // TODO consoleInputValidator template specialization for const
        // char[] and also std::string
        std::cin >> flag;
        std::transform(flag.begin(), flag.end(), flag.begin(), toupper);
    } while (flag == "Y" || flag == "YES");

    return EXIT_SUCCESS;
}