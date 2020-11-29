//
// Created by Александр Сафиюлин on 27.11.2020.
//

#ifndef FIRSTTASK_ERRORCODE_HPP
#define FIRSTTASK_ERRORCODE_HPP

#include <iostream>
#include <string>
#include <sstream>

namespace task::helpers {
    enum Error : unsigned short {
        NO_ERROR,
        NOT_IMPLEMENTED_ERROR,
        MEMORY_LACK_ERROR,
        MEMORY_CLEAN_ERROR,
        PARSE_DATA_ERROR,
        CHECK_DATA_ERROR,
        ARGUMENT_ZERO_ERROR
    };

    std::string ToString(Error error) {

        auto formatErrorString = [&error](const char string[]) -> std::string {
            std::stringstream ss;
            ss << "Code " << static_cast<unsigned short>(error) << ": " <<
            string;

            return ss.str();
        };

        switch (error) {
            case NOT_IMPLEMENTED_ERROR: {
                return formatErrorString("Not implemented error");
            }
            case MEMORY_LACK_ERROR: {
                return formatErrorString("Memory lack error");
            }
            case MEMORY_CLEAN_ERROR: {
                return formatErrorString("Memory clean error");
            }
            case PARSE_DATA_ERROR: {
                return formatErrorString("Parse data error");
            }
            case CHECK_DATA_ERROR: {
                return formatErrorString("Check data error");
            }
            case ARGUMENT_ZERO_ERROR: {
                return formatErrorString("Argument zero error");
            }
            default: {
                return formatErrorString("No error");
            }
        }
    }
}
#endif //FIRSTTASK_ERRORCODE_HPP
