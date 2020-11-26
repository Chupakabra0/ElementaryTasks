#include <algorithm>
#include <iostream>
#include <string>

#include "Envelope.hpp"
#include "View.hpp"
#include "Helpers.hpp"

int main(int argc, char* argv[]) {
    std::string flag;
    do {
        try {
            double firstHeight, firstWidth;
            double secondHeight, secondWidth;
            if (argc >= 5) {
                firstHeight  = task::helpers::ConvertString<double>(argv[1]);
                firstWidth   = task::helpers::ConvertString<double>(argv[2]);
                secondHeight = task::helpers::ConvertString<double>(argv[3]);
                secondWidth  = task::helpers::ConvertString<double>(argv[4]);
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

            if (!std::cin) {
                throw std::runtime_error("Bad input...");
            }
            if (firstHeight < 0.0 || firstWidth < 0.0 || secondHeight < 0.0 || secondWidth < 0.0) {
                throw std::runtime_error("Heights and widths must be greater than 0...");
            }

            const task::second::Envelope firstEnvelope(firstHeight, firstWidth);
            const task::second::Envelope secondEnvelope(secondHeight, secondWidth);

            const auto* view = new task::second::View(firstEnvelope, secondEnvelope);
            view->Out();
            delete view;

            std::cout << "Continue? [y/Yes]:";
            std::cin >> flag;
            std::transform(flag.begin(), flag.end(), flag.begin(), toupper);
        }
        catch (std::exception &exception) {
            std::cerr << exception.what() << std::endl;
            return 1;
        }
    } while (flag != "Y" || flag != "YES");
    return 0;
}
