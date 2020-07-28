#include <filesystem>

#include "DropDirNode.h"
#include "../../../Common/Exceptions/DirectoryNotFoundException.h"

using namespace FQL;

namespace fs = std::filesystem;

DropDirNode::DropDirNode(const char *dir, bool dropIfExists) : DropDirNode(std::string(dir), dropIfExists)
{
}

DropDirNode::DropDirNode(const std::string &dir, bool dropIfExists)
{
    this->dir = dir;
    this->dropIfExists = dropIfExists;
}

bool DropDirNode::Execute()
{
    bool exists = fs::exists(this->dir);

    if (!exists && this->dropIfExists)
    {
        return true;
    }

    if (!exists && !this->dropIfExists)
    {
        throw new DirectoryNotFoundException(this->dir);
    }

    return fs::remove(this->dir);
}

void DropDirNode::DumpTree(std::ostream &out, int indent) const
{
}
