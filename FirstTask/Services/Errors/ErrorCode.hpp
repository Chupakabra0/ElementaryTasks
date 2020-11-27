//
// Created by Александр Сафиюлин on 27.11.2020.
//

#ifndef FIRSTTASK_ERRORCODE_HPP
#define FIRSTTASK_ERRORCODE_HPP

#include <string>
#include <iostream>

namespace task::helpers {
    enum Error : short {
        NO_ERROR,
        MEMORY_LACK_ERROR,
        PARSE_DATA_ERROR,
        CHECK_DATA_ERROR
    };

    std::string ToString(Error error) {
        switch (error) {
            case MEMORY_LACK_ERROR: {
                return std::string("Code 1: Memory lack error");
            }
            case PARSE_DATA_ERROR: {
                return std::string("Code 2: Parse data error");
            }
            case CHECK_DATA_ERROR: {
                return std::string("Code 3: Check data error");
            }
            default: {
                return std::string("Code 0: No error");
            }
        }
    }
}
#endif //FIRSTTASK_ERRORCODE_HPP
