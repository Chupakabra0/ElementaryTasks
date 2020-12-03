#include <iostream>
#include <regex>

#include "Models/Board/BoardFactory.hpp"
#include "ViewModels/ViewModel.hpp"
#include "View/View.hpp"
#include "Services/ConsoleValidator/ConsoleArgsValidator.hpp"

int main(int argc, char* argv[]) {

    // TIP: maybe func or class or functor
    const auto nullCheck = [](const auto& pointer) -> void {
        if (nullptr != pointer) return;
        task::helpers::ErrorHandler::AssertAndExit
                (task::helpers::Error::MEMORY_LACK_ERROR);
    };

    std::unique_ptr<unsigned short> rows, columns;
    std::unique_ptr<task::helpers::ConsoleArgsValidator> consoleArgsValidator
            (new(std::nothrow) task::helpers::ConsoleArgsValidator(argc, argv));
    nullCheck(consoleArgsValidator);

    const auto checkLetters = [](const char string[]) -> bool {
        const std::regex lettersCheck(R"((\d+?))");
        return std::regex_match(string, lettersCheck);
    };
    
    if (consoleArgsValidator->CheckEnoughArgc(3)) {
        rows    = std::move(consoleArgsValidator->ValidateByIndex<unsigned
                short>(1, checkLetters));
        nullCheck(rows);

        columns = std::move(consoleArgsValidator->ValidateByIndex<unsigned
                short>(2, checkLetters));
        nullCheck(columns);
    }
    else {
        std::cout << "Arguments error..." << std::endl;
        std::cout << "FirstTask.exe rowsCount columnsCount" << std::endl;

        return EXIT_SUCCESS;
    }

    std::unique_ptr<task::first::BoardFactory> boardFactory
        (new(std::nothrow) task::first::BoardFactory('*', ' '));
    nullCheck(boardFactory);

    std::unique_ptr<task::first::Board> board
        (std::move(boardFactory->CreateBoard(*rows, *columns)));
    nullCheck(board);

    std::unique_ptr<task::first::ViewModel> viewModel
        (new(std::nothrow) task::first::ViewModel(*board));
    nullCheck(viewModel);

    std::unique_ptr<task::first::View> view
        (new(std::nothrow) task::first::View(*viewModel));
    nullCheck(view);

    view->Out();

    return EXIT_SUCCESS;
}