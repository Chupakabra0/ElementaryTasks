#include <algorithm>
#include <iostream>
//#include <sstream>
#include <string>

#include "Envelope.hpp"
#include "View.hpp"

int main(int argc, char* argv[]) {
    std::string flag;
    do {
        try {
            double firstHeight, firstWidth;
            double secondHeight, secondWidth;
            if (argc >= 5) {
                firstHeight = strtod(argv[1], nullptr);
                firstWidth = strtod(argv[2], nullptr);
                secondHeight = strtod(argv[3], nullptr);
                secondWidth = strtod(argv[4], nullptr);
//                std::stringstream ss;
//                ss << argv[1];
//                ss >> firstHeight;
//                if (ss.fail()) {
//                    throw std::runtime_error("Bad arguments...");
//                }

//                ss.clear();
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
