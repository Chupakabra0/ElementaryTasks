//
// Created by Александр Сафиюлин on 30.11.2020.
//

#ifndef THIRDTASK_STRINGCLEANER_HPP
#define THIRDTASK_STRINGCLEANER_HPP

#include <string>

namespace task::helpers {
    class StringCleaner {
    public:
        StringCleaner()                     = delete;
        StringCleaner(const StringCleaner&) = default;
        StringCleaner(StringCleaner&&)      = default;

        explicit StringCleaner(char toClean) : toClean_(toClean) {}

        [[nodiscard]] std::string Clean(const std::string& string) const {
            std::string result = string;
            result.erase(remove(result.begin(), result.end(), this->toClean_),
                         result.end());
            return result;
        }

    private:
        char toClean_;
    };
}

#endif //THIRDTASK_STRINGCLEANER_HPP
