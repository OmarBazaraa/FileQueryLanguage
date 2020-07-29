#include <filesystem>

#include "DropNode.h"
#include "../../../Common/Exceptions/DirectoryNotFoundException.h"

using namespace FQL;

namespace fs = std::filesystem;

DropNode::DropNode(DirectoryNode *dir, bool dropIfExists)
    : dir(dir), dropIfExists(dropIfExists)
{
    // TODO: ensure not null dir.
}

bool DropNode::Execute()
{
    bool exists = fs::exists(this->dir->GetDirectory());

    if (!exists && this->dropIfExists)
    {
        return true;
    }

    if (!exists && !this->dropIfExists)
    {
        throw new DirectoryNotFoundException(this->dir->GetDirectory());
    }

    return fs::remove(this->dir->GetDirectory());
}

void DropNode::DumpTree(std::ostream &out, int indent) const
{
    out << std::string(indent, ' ');
    out << "DROP DIRECTORY " << (this->dropIfExists ? "IF EXISTS " : "");
    this->dir->DumpTree(out, 0);
}
