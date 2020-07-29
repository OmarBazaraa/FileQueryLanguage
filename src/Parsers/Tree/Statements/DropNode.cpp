#include <filesystem>

#include "DropNode.h"
#include "../../../Common/Exceptions/DirectoryNotFoundException.h"

using namespace FQL;

namespace fs = std::filesystem;

DropNode::DropNode(const char *dir, bool dropIfExists)
    : DropNode(std::string(dir), dropIfExists)
{
}

DropNode::DropNode(const std::string &dir, bool dropIfExists)
    : dir(dir), dropIfExists(dropIfExists)
{
}

bool DropNode::Execute()
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

void DropNode::DumpTree(std::ostream &out, int indent) const
{
}
