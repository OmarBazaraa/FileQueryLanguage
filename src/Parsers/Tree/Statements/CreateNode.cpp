#include <filesystem>

#include "CreateNode.h"
#include "../../../Common/Exceptions/DirectoryAlreadyExistsException.h"

using namespace FQL;

namespace fs = std::filesystem;

CreateNode::CreateNode(const std::string &dir, bool createIfNotExists)
    : dir(dir), createIfNotExists(createIfNotExists)
{
}

bool CreateNode::Execute()
{
    if (!this->createIfNotExists && fs::exists(this->dir))
    {
        throw new DirectoryAlreadyExistsException(this->dir);
    }

    return fs::create_directory(this->dir);
}

void CreateNode::DumpTree(std::ostream &out, int indent) const
{
}
