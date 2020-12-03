#include <iostream>
#include <regex>

#include "Models/Board/BoardFactory.hpp"
#include "ViewModels/ViewModel.hpp"
#include "View/View.hpp"
#include "Services/ConsoleValidator/ConsoleArgsValidator.hpp"

int main(int argc, char* argv[]) {

    std::unique_ptr<unsigned short> rowsCount, columnsCount;
    std::unique_ptr<task::helpers::ConsoleArgsValidator> consoleArgsValidator
            (new(std::nothrow) task::helpers::ConsoleArgsValidator(argc, argv));
    if (nullptr == consoleArgsValidator) {
        task::helpers::ErrorHandler::AssertAndExit
            (task::helpers::Error::MEMORY_LACK_ERROR);
    }

    const auto checkLetters = [](const char string[]) -> bool {
        const std::regex lettersCheck(R"((\d+?))");
        return std::regex_match(string, lettersCheck);
    };

    if (consoleArgsValidator->CheckEnoughArgc(3)) {
        rowsCount    = std::move(consoleArgsValidator->ValidateByIndex<unsigned
                short>(1, checkLetters));
        if (nullptr == rowsCount) {
            task::helpers::ErrorHandler::AssertAndExit
                    (task::helpers::Error::PARSE_DATA_ERROR);
        }

        columnsCount = std::move(consoleArgsValidator->ValidateByIndex<unsigned
                short>(2, checkLetters));
        if (nullptr == columnsCount) {
            task::helpers::ErrorHandler::AssertAndExit
                    (task::helpers::Error::PARSE_DATA_ERROR);
        }
    }
    else {
        std::cout << "Arguments error..." << std::endl;
        std::cout << "FirstTask.exe rowsCount columnsCount" << std::endl;

        return EXIT_SUCCESS;
    }

    std::unique_ptr<task::first::BoardFactory> boardFactory
        (new(std::nothrow) task::first::BoardFactory('*', ' '));
    if (nullptr == boardFactory) {
        task::helpers::ErrorHandler::AssertAndExit
                (task::helpers::Error::MEMORY_LACK_ERROR);
    }

    std::unique_ptr<task::first::Board> board
        (std::move(boardFactory->CreateBoard(*rowsCount, *columnsCount)));
    if (nullptr == board) {
        task::helpers::ErrorHandler::AssertAndExit
                (task::helpers::Error::MEMORY_LACK_ERROR);
    }

    std::unique_ptr<task::first::ViewModel> viewModel
        (new(std::nothrow) task::first::ViewModel(*board));
    if (nullptr == viewModel) {
        task::helpers::ErrorHandler::AssertAndExit
                (task::helpers::Error::MEMORY_LACK_ERROR);
    }

    std::unique_ptr<task::first::View> view
        (new(std::nothrow) task::first::View(*viewModel));
    if (nullptr == view) {
        task::helpers::ErrorHandler::AssertAndExit
                (task::helpers::Error::MEMORY_LACK_ERROR);
    }

    view->Out();

    return EXIT_SUCCESS;
}