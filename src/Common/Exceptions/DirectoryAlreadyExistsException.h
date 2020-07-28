#ifndef __DIRECTORY_EXISTING_EXCEPTION_H_
#define __DIRECTORY_EXISTING_EXCEPTION_H_

#include "DirectoryException.h"

namespace FQL
{
    class DirectoryAlreadyExistsException : public DirectoryException
    {
    public:
        DirectoryAlreadyExistsException(std::string path)
            : DirectoryException(path, "Directory " + path + " already exists.")
        {
        }
    };
}

#endif
