#ifndef __BASE_EXCEPTION_H_
#define __BASE_EXCEPTION_H_

#include <iostream>

namespace FileManager {

    class BaseException {
    public:

        std::string message;

        BaseException(std::string message) {
            this->message = message;
        }
    };
}

#endif
