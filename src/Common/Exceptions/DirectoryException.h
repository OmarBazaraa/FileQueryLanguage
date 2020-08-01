#pragma once

#include <Common/Exceptions/BaseException.h>

namespace FQL
{
    class DirectoryException : public BaseException
    {
    protected:
        std::string path;

    public:
        DirectoryException(const std::string& path, const std::string& message)
            : BaseException(message)
        {
            this->path = path;
        }

        const std::string& GetPath() const
        {
            return this->path;
        }
    };
}
