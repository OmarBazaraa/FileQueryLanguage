#ifndef __DIRECTORY_NOT_FOUND_EXCEPTION_H_
#define __DIRECTORY_NOT_FOUND_EXCEPTION_H_

#include "BaseException.h"

namespace FileManager {

    class DirectoryNotFoundException : public BaseException {
    public:

        std::string path;

        DirectoryNotFoundException(std::string path)
        : BaseException("Directory " + path + " does not exist.") {
            this->path = path;
        }
    };
}

#endif
