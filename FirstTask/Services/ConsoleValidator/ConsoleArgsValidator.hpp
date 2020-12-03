//
// Created by Александр Сафиюлин on 27.11.2020.
//

#ifndef FIRSTTASK_CONSOLEARGSVALIDATOR_HPP
#define FIRSTTASK_CONSOLEARGSVALIDATOR_HPP

#include "../Converter/Converter.hpp"

namespace task::helpers {
    class ConsoleArgsValidator {
    public:
        ConsoleArgsValidator()                            = delete;
        ConsoleArgsValidator(const ConsoleArgsValidator&) = default;
        ConsoleArgsValidator(ConsoleArgsValidator&&)      = default;

        ConsoleArgsValidator(unsigned argc, char **argv)
                : argc_(argc), argv_(argv) {}

        template<class Type>
        std::unique_ptr<Type> ValidateByIndex(const unsigned index, bool
        predicate(const char[]) = nullptr) const {
            auto result = std::move(task::helpers::Converter<Type>::ConvertString
            (this->argv_[index], predicate));

            return result;
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

        ~ConsoleArgsValidator() = default;

    private:
        unsigned argc_;
        char**   argv_;
    };
}

#endif //FIRSTTASK_CONSOLEARGSVALIDATOR_HPP
