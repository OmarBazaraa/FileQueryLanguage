#pragma once

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
