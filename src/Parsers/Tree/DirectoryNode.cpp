#include "DirectoryNode.h"

using namespace FQL;

DirectoryNode::DirectoryNode(const std::string &path, bool recursive)
{
    this->path = path;
    this->recursive = recursive;
}

DirectoryNode::DirectoryNode(const std::string &path, const std::string &alias, bool recursive)
    : DirectoryNode(path, recursive)
{
    this->alias = alias;
}

bool DirectoryNode::IsRecursive() const
{
    return this->recursive;
}

const std::string &DirectoryNode::GetPath() const
{
    return this->path;
}

const std::string &DirectoryNode::GetAlias() const
{
    return this->alias;
}


void DirectoryNode::DumpTree(std::ostream &out, int indent) const
{
    out << std::string(indent, ' ');
    out << "\"" << this->path << "\"";
    out << (this->recursive ? " RECURSIVE" : "");
    out << (this->alias.size() > 0 ? " AS " + this->alias : "");
}
