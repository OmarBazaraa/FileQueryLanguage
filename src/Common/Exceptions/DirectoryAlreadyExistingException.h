#ifndef __DIRECTORY_EXISTING_EXCEPTION_H_
#define __DIRECTORY_EXISTING_EXCEPTION_H_

#include "DirectoryException.h"

namespace FileManager
{
    class DirectoryAlreadyExistingException : public DirectoryException
    {
    public:
        DirectoryAlreadyExistingException(std::string path)
            : DirectoryException(path, "Directory " + path + " already exists.")
        {
        }
    };
}

#endif
