#include <iostream>
#include <sstream>

#include "ChessBoard.hpp"
#include "View.hpp"

int main(int argc, char* argv[]) {
    try {
        int rows, columns;

        if (argc >= 3) {
            std::stringstream ss;
            ss << argv[1];
            ss >> rows;
            if (ss.fail()) {
                throw std::runtime_error("Bad arguments...");
            }
            ss.clear();

            ss << argv[2];
            ss >> columns;
            if (ss.fail()) {
                throw std::runtime_error("Bad arguments...");
            }
        }
        else {
            std::cout << "Enter count of rows and columns:" << std::endl;
            std::cin >> rows >> columns;
        }

        if (!std::cin) {
            throw std::runtime_error("Bad input...");
        }
        if (rows < 0 || columns < 0) {
            throw std::runtime_error("Rows or columns can't be lesser than 0...");
        }
        if (rows > std::numeric_limits<unsigned short>::max() || columns > std::numeric_limits<unsigned short>::max()) {
            throw std::runtime_error("Rows or columns can't be greater than 65535...");
        }

        auto* view = new task::first::View(task::first::Board(rows, columns));
        view->Out();
        delete view;
    }
    catch (std::exception& exception) {
        std::cerr << exception.what() << std::endl;
        return 1;
    }
    return 0;
}