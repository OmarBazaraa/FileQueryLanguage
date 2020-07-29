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
        DirectoryException(const std::string &path, const std::string &message)
            : BaseException(message)
        {
            this->path = path;
        }

        const std::string &GetPath() const
        {
            return this->path;
        }
    };
}

#endif
