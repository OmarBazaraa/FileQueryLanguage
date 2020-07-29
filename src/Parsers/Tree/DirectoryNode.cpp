#include "DirectoryNode.h"

using namespace FQL;

DirectoryNode::DirectoryNode(const std::string &dir, bool recursive)
{
    this->directory = dir;
    this->recursive = recursive;
}

DirectoryNode::DirectoryNode(const std::string &dir, const std::string &alias, bool recursive)
    : DirectoryNode(dir, recursive)
{
    this->alias = alias;
}

bool DirectoryNode::IsRecursive() const
{
    return this->recursive;
}

const std::string &DirectoryNode::GetDirectory() const
{
    return this->directory;
}

const std::string &DirectoryNode::GetAlias() const
{
    return this->alias;
}

void DirectoryNode::DumpTree(std::ostream &out, int indent) const
{
    out << std::string(indent, ' ');
    out << this->directory << (this->recursive ? " RECURSIVE" : "");
    out << (this->alias.size() > 0 ? " AS " + this->alias : "");
}
