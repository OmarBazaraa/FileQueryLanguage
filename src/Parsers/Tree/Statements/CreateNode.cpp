#include <filesystem>

#include <Common/Exceptions.h>
#include <Parsers/Tree/Statements/CreateNode.h>

using namespace FQL;

namespace fs = std::filesystem;

CreateNode::CreateNode(DirectoryNode* dir, bool createIfNotExists)
{
    // TODO: ensure not null directory.
    this->dir = dir;
    this->createIfNotExists = createIfNotExists;
}

bool CreateNode::Execute()
{
    if (!this->createIfNotExists && fs::exists(this->dir->GetPath()))
    {
        throw new DirectoryAlreadyExistsException(this->dir->GetPath());
    }

    return fs::create_directory(this->dir->GetPath());
}

void CreateNode::DumpTree(std::ostream& out, int indent) const
{
    out << std::string(indent, ' ');
    out << "CREATE DIRECTORY " << (this->createIfNotExists ? "IF NOT EXISTS " : "");
    this->dir->DumpTree(out, 0);
}
