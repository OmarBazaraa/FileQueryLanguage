#include <filesystem>

#include "CreateDirNode.h"
#include "../../../Common/Exceptions/DirectoryAlreadyExistsException.h"

using namespace FQL;

namespace fs = std::filesystem;

CreateDirNode::CreateDirNode(const std::string &dir, bool createIfNotExists)
{
    this->dir = dir;
    this->createIfNotExists = createIfNotExists;
}

bool CreateDirNode::Execute()
{
    if (!this->createIfNotExists && fs::exists(this->dir))
    {
        throw new DirectoryAlreadyExistsException(this->dir);
    }

    return fs::create_directory(this->dir);
}

void CreateDirNode::DumpTree(std::ostream &out, int indent) const
{
}
