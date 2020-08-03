#pragma once

#include "Common/Exceptions/DirectoryException.h"

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
