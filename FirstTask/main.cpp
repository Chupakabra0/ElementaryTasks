#include <iostream>
#include <regex>

#include "Models/Board/BoardFactory.hpp"
#include "ViewModels/ViewModel.hpp"
#include "View/View.hpp"
#include "Services/ConsoleValidator/ConsoleArgsValidator.hpp"

int main(int argc, char* argv[]) {

    NO_THROW_NEW(rows, unsigned short());
    NO_THROW_NEW(columns, unsigned short());
    NO_THROW_NEW(consoleArgsValidator, task::helpers::ConsoleArgsValidator(argc, argv));

    auto checkLetters = [](const char string[]) -> bool {
        const std::regex lettersCheck(R"((\d+?))");
        return std::regex_match(string, lettersCheck);
    };
 
    // TODO: maybe make input-class
    if (consoleArgsValidator->CheckEnoughArgc(3)) {
        rows    = consoleArgsValidator->ValidateByIndex<unsigned short>(1,
                                                                    checkLetters);
        columns = consoleArgsValidator->ValidateByIndex<unsigned short>(2,
                                                                    checkLetters);
    }
    else {
        std::cout << "Arguments error..." << std::endl;
        std::cout << "FirstTask.exe rowsCount columnsCount" << std::endl;

        NO_THROW_DELETE(consoleArgsValidator);

        return EXIT_SUCCESS;
    }

    NO_THROW_DELETE(consoleArgsValidator);

    NO_THROW_NEW(boardFactory, task::first::BoardFactory('*', ' '));
    auto* board = boardFactory->CreateBoard(*rows, *columns);
    NO_THROW_NEW(viewModel, task::first::ViewModel(*board));
    NO_THROW_NEW(view, task::first::View(*viewModel));

    view->Out();

    NO_THROW_DELETE(board);
    NO_THROW_DELETE(view);
    NO_THROW_DELETE(viewModel);
    NO_THROW_DELETE(boardFactory);
    NO_THROW_DELETE(rows);
    NO_THROW_DELETE(columns);

    return EXIT_SUCCESS;
}