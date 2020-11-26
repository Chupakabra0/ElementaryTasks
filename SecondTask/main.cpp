#include <algorithm>
#include <iostream>
#include <string>

#include "Models/Envelope/Envelope.hpp"
#include "ViewModels/View.hpp"
#include "Services/Converter.hpp"

int main(int argc, char* argv[]) {
    std::string flag;
    auto firstLaunch = true;
    do {
        double firstHeight, firstWidth;
        double secondHeight, secondWidth;

        // TODO multiple argv choose
        if (firstLaunch && argc >= 5) {
            firstHeight  = task::helpers::Converter<double>::ConvertString(argv[1]);
            firstWidth   = task::helpers::Converter<double>::ConvertString(argv[2]);
            secondHeight = task::helpers::Converter<double>::ConvertString(argv[3]);
            secondWidth  = task::helpers::Converter<double>::ConvertString(argv[4]);
            firstLaunch = false;
        }
        else {
            std::cout << "Creating first envelope." << std::endl << "Enter height:" << std::endl;
            std::cin >> firstHeight;
            std::cout << "Enter width:" << std::endl;
            std::cin >> firstWidth;

            std::cout << "Creating second envelope." << std::endl << "Enter height:" << std::endl;
            std::cin >> secondHeight;
            std::cout << "Enter width:" << std::endl;
            std::cin >> secondWidth;
        }

        task::helpers::ErrorHandler::AssertAndExit(!std::cin, "Bad input...");
        task::helpers::ErrorHandler::AssertAndExit
            (firstHeight < 0.0 || firstWidth < 0.0 || secondHeight < 0.0 ||
            secondWidth < 0.0, "Heights and widths must be greater than 0...");

        const task::second::Envelope firstEnvelope(firstHeight, firstWidth);
        const task::second::Envelope secondEnvelope(secondHeight, secondWidth);

        const auto* view = new task::second::View(firstEnvelope, secondEnvelope);
        view->Out();
        delete view;

        std::cout << "Continue? [y/Yes]:";
        std::cin >> flag;
        std::transform(flag.begin(), flag.end(), flag.begin(), toupper);
    } while (flag != "Y" || flag != "YES");
    return 0;
}
