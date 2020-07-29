#include <filesystem>

#include "CreateNode.h"
#include "../../../Common/Exceptions/DirectoryAlreadyExistsException.h"

using namespace FQL;

namespace fs = std::filesystem;

CreateNode::CreateNode(DirectoryNode *dir, bool createIfNotExists)
    : dir(dir), createIfNotExists(createIfNotExists)
{
    // TODO: ensure not null directory.
}

bool CreateNode::Execute()
{
    if (!this->createIfNotExists && fs::exists(this->dir->GetDirectory()))
    {
        throw new DirectoryAlreadyExistsException(this->dir->GetDirectory());
    }

    return fs::create_directory(this->dir->GetDirectory());
}

void CreateNode::DumpTree(std::ostream &out, int indent) const
{
    out << std::string(indent, ' ');
    out << "CREATE DIRECTORY " << (this->createIfNotExists ? "IF NOT EXISTS " : "");
    this->dir->DumpTree(out, 0);
}
