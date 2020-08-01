#ifndef __DIRECTORY_NOT_FOUND_EXCEPTION_H_
#define __DIRECTORY_NOT_FOUND_EXCEPTION_H_

#include <Common/Exceptions/DirectoryException.h>

namespace FQL
{
    class DirectoryNotFoundException : public DirectoryException
    {
    public:
        DirectoryNotFoundException(const std::string& path)
            : DirectoryException(path, "Directory '" + path + "' does not exist.")
        {
        }
    };
}

#endif
