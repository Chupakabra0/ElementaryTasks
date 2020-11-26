#include <iostream>

#include "Models/Board/Board.hpp"
#include "ViewModels/View.hpp"
#include "Services/ErrorHandler.hpp"
#include "Services/Converter.hpp"
#include "Models/Board/BoardFactory.hpp"

int main(int argc, char* argv[]) {
    int rows, columns;

    // TODO: maybe make input-class
    if (argc >= 3) {
        rows    = task::helpers::Converter<int>::ConvertString(argv[1]);
        columns = task::helpers::Converter<int>::ConvertString(argv[2]);
    }
    else {
        std::cout << "Enter count of rows and columns:" << std::endl;
        std::cin >> rows >> columns;
    }

    task::helpers::ErrorHandler::AssertAndExit(!std::cin, "Bad input...");
    task::helpers::ErrorHandler::AssertAndExit(rows < std::numeric_limits<unsigned short>::min() || columns < std::numeric_limits<unsigned short>::min(), "Rows or columns can't be lesser than 0...");
    task::helpers::ErrorHandler::AssertAndExit(rows > std::numeric_limits<unsigned short>::max() || columns > std::numeric_limits<unsigned short>::max(), "Rows or columns can't be greater than 65535...");

    // TODO: functional object for catching new errors and removing
    // repetitive code
    auto* boardFactory = new(std::nothrow) task::first::BoardFactory('*', ' ');
    task::helpers::ErrorHandler::AssertAndExit(!boardFactory, "Memory lack...");

    auto* board        = boardFactory->CreateBoard(rows, columns);
    task::helpers::ErrorHandler::AssertAndExit(!board, "Memory lack...");

    auto* view         = new(std::nothrow) task::first::View(*board);
    task::helpers::ErrorHandler::AssertAndExit(!view, "Memory lack...");

    view->Out();
    // TODO: maybe make some smart pointers
    delete view;
    delete board;
    delete boardFactory;

    return EXIT_SUCCESS;
}