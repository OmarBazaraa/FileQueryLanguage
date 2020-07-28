#ifndef __DIRECTORY_EXCEPTION_H_
#define __DIRECTORY_EXCEPTION_H_

#include <string>

#include "BaseException.h"

namespace FQL
{
    class DirectoryException : public BaseException
    {
    protected:
        std::string path;

    public:
        DirectoryException(std::string path, std::string message)
            : BaseException(message)
        {
            this->path = path;
        }

        std::string GetPath() const
        {
            return this->path;
        }
    };
}

#endif
