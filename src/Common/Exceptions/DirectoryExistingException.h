#ifndef __DIRECTORY_EXISTING_EXCEPTION_H_
#define __DIRECTORY_EXISTING_EXCEPTION_H_

#include "BaseException.h"

namespace FileManager {

    class DirectoryExistingException : public BaseException {
    public:

        std::string path;

        DirectoryExistingException(std::string path)
        : BaseException("Directory " + path + " already exists.") {
            this->path = path;
        }
    };
}

#endif
