//
// Created by Александр Сафиюлин on 27.11.2020.
//

#ifndef FIRSTTASK_CONSOLEVALIDATOR_HPP
#define FIRSTTASK_CONSOLEVALIDATOR_HPP

#include "../Converter/Converter.hpp"

namespace task::helpers {
    class ConsoleValidator {
    public:
        ConsoleValidator()                        = default;
        ConsoleValidator(const ConsoleValidator&) = default;
        ConsoleValidator(ConsoleValidator&&)      = default;

        ConsoleValidator(unsigned argc, char **argv)
                : argc_(argc), argv_(argv) {}

        template<class Type>
        Type ValidateByIndex(unsigned index) const {
            return task::helpers::Converter<Type>::ConvertString
            (this->argv_[index]);
        }

        [[nodiscard]] bool CheckEnoughArgc(unsigned argc) const {
            return this->argc_ >= argc;
        }

        [[nodiscard]] const char* GetPath() const {
            return this->argv_[0];
        }

        [[nodiscard]] unsigned GetArgc() const {
            return this->argc_;
        }

        [[nodiscard]] char** GetArgv() const {
            return this->argv_;
        }

        ~ConsoleValidator() = default;

    private:
        unsigned argc_;
        char **argv_;
    };
}

#endif //FIRSTTASK_CONSOLEVALIDATOR_HPP
