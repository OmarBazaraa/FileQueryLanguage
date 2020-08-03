#include "Parsers/Tree/Statements/DeleteNode.h"

using namespace FQL;

DeleteNode::DeleteNode(DirectoryNode* dir)
{
    // TODO: ensure not null directory.
    this->dir = dir;
}

DeleteNode::DeleteNode(DirectoryNode* dir, const std::vector<ClauseNode*>& clauses)
    : DeleteNode(dir)
{
    this->clauses = clauses;
}

DeleteNode::~DeleteNode()
{
    if (this->dir != NULL)
    {
        delete this->dir;
    }

    for (auto p : this->clauses)
    {
        if (p != NULL)
        {
            delete p;
        }
    }
}

bool DeleteNode::Execute()
{
    return true;
}

void DeleteNode::DumpTree(std::ostream& out, int indent) const
{
    out << std::string(indent, ' ');
    out << "DELETE FROM ";

    this->dir->DumpTree(out, 0);

    for (auto p : this->clauses)
    {
        if (p != NULL)
        {
            out << std::endl;
            p->DumpTree(out, 0);
        }
    }
}
