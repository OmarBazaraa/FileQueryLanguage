#ifndef __DIRECTORY_EXISTING_EXCEPTION_H_
#define __DIRECTORY_EXISTING_EXCEPTION_H_

#include <Common/Exceptions/DirectoryException.h>

namespace FQL
{
    class DirectoryAlreadyExistsException : public DirectoryException
    {
    public:
        DirectoryAlreadyExistsException(const std::string& path)
            : DirectoryException(path, "Directory '" + path + "' already exists.")
        {
        }
    };
}

#endif
