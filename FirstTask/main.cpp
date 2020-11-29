#include <iostream>

#include "Models/Board/BoardFactory.hpp"
#include "ViewModels/ViewModel.hpp"
#include "View/View.hpp"
#include "Services/ConsoleValidator/ConsoleValidator.hpp"

int main(int argc, char* argv[]) {

    unsigned short rows, columns;
    NO_THROW_NEW(consoleValidator, task::helpers::ConsoleValidator(argc, argv));

    // TODO: maybe make input-class
    if (consoleValidator->CheckEnoughArgc(3)) {
        rows    = consoleValidator->ValidateByIndex<unsigned short>(1);
        columns = consoleValidator->ValidateByIndex<unsigned short>(2);
    }
    else {
        std::cout << "Arguments error:" << std::endl;
        std::cout << "FirstTask.exe rowsCount columnsCount" << std::endl;

        NO_THROW_DELETE(consoleValidator);

        return EXIT_SUCCESS;
    }

    NO_THROW_DELETE(consoleValidator);

    NO_THROW_NEW(boardFactory, task::first::BoardFactory('*', ' '));
    auto* board = boardFactory->CreateBoard(rows, columns);
    NO_THROW_NEW(viewModel, task::first::ViewModel(*board));
    NO_THROW_NEW(view, task::first::View(*viewModel));

    view->Out();
    
    NO_THROW_DELETE(board);
    NO_THROW_DELETE(view);
    NO_THROW_DELETE(viewModel);
    NO_THROW_DELETE(boardFactory);

    return EXIT_SUCCESS;
}