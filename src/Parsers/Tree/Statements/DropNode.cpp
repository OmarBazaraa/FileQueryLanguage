#include <filesystem>

#include "Common/Exceptions.h"
#include "Parsers/Tree/Statements/DropNode.h"

using namespace FQL;

namespace fs = std::filesystem;

DropNode::DropNode(DirectoryNode* dir, bool dropIfExists)
{
    // TODO: ensure not null dir.
    this->dir = dir;
    this->dropIfExists = dropIfExists;
}

bool DropNode::Execute()
{
    bool exists = fs::exists(this->dir->GetPath());

    if (!exists && this->dropIfExists)
    {
        return true;
    }

    if (!exists && !this->dropIfExists)
    {
        throw new DirectoryNotFoundException(this->dir->GetPath());
    }

    return fs::remove(this->dir->GetPath());
}

void DropNode::DumpTree(std::ostream& out, int indent) const
{
    out << std::string(indent, ' ');
    out << "DROP DIRECTORY " << (this->dropIfExists ? "IF EXISTS " : "");
    this->dir->DumpTree(out, 0);
}
