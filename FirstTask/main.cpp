#include <iostream>

#include "Models/Board/BoardFactory.hpp"

#include "ViewModels/ViewModel.hpp"

#include "View/View.hpp"

#include "Services/Errors/ErrorHandler.hpp"
#include "Services/ConsoleValidator/ConsoleValidator.hpp"

int main(int argc, char* argv[]) {

    unsigned short rows, columns;
    auto* consoleValidator = new(std::nothrow) task::helpers::ConsoleValidator(argc,
                                                                     argv);

    // TODO: maybe make input-class
    if (consoleValidator->CheckEnoughArgc(3)) {
        rows    = consoleValidator->ValidateByIndex<unsigned short>(1);
        columns = consoleValidator->ValidateByIndex<unsigned short>(2);
    }
    else {
        std::cout << "Launch help:" << std::endl;
        std::cout << "FirstTask.exe rowsCount columnsCount" << std::endl;

        delete consoleValidator;
        return EXIT_SUCCESS;
    }

    // TODO: functional object for catching new errors and removing
    // repetitive code
    // MAKE THIS SHIT!
    auto* boardFactory = new(std::nothrow) task::first::BoardFactory('*', ' ');
    if (!boardFactory) {
        task::helpers::ErrorHandler::AssertAndExit
                (task::helpers::Error::MEMORY_LACK_ERROR);
    }

    auto* board = boardFactory->CreateBoard(rows, columns);
    if (!board) {
        task::helpers::ErrorHandler::AssertAndExit
                (task::helpers::Error::MEMORY_LACK_ERROR);
    }

    auto* viewModel = new(std::nothrow) task::first::ViewModel(*board);
    if (!viewModel) {
        task::helpers::ErrorHandler::AssertAndExit
                (task::helpers::Error::MEMORY_LACK_ERROR);
    }

    auto* view = new(std::nothrow) task::first::View(*viewModel);
    if (!view) {
        task::helpers::ErrorHandler::AssertAndExit
                (task::helpers::Error::MEMORY_LACK_ERROR);
    }

    view->Out();

    // TODO: maybe make some smart pointers
    delete view;
    delete viewModel;
    delete board;
    delete boardFactory;
    delete consoleValidator;

    return EXIT_SUCCESS;
}