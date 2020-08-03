#include "Parsers/Tree/Statements/UpdateNode.h"

using namespace FQL;

UpdateNode::UpdateNode(DirectoryNode* dir, const std::vector<UpdateAssignmentNode*>& assignments)
{
    // TODO: ensure not null directory.
    // TODO: ensure not emtpy assignments.
    this->dir = dir;
    this->assignments = assignments;
}

UpdateNode::UpdateNode(DirectoryNode* dir, const std::vector<UpdateAssignmentNode*>& assignments, const std::vector<ClauseNode*>& clauses)
    : UpdateNode(dir, assignments)
{
    this->clauses = clauses;
}

UpdateNode::~UpdateNode()
{
    if (this->dir != NULL)
    {
        delete this->dir;
    }

    for (auto p : this->assignments)
    {
        delete p;
    }

    for (auto p : this->clauses)
    {
        if (p != NULL)
        {
            delete p;
        }
    }
}

bool UpdateNode::Execute()
{
    return true;
}

void UpdateNode::DumpTree(std::ostream& out, int indent) const
{
    out << std::string(indent, ' ');
    out << "UPDATE ";

    this->dir->DumpTree(out, 0);

    out << std::endl;
    out << "SET";

    for (int i = 0; i < this->assignments.size(); ++i)
    {
        out << std::endl;
        this->assignments[i]->DumpTree(out, indent + 4);
        out << (i + 1 < this->assignments.size() ? "," : "");
    }

    for (auto p : this->clauses)
    {
        if (p != NULL)
        {
            out << std::endl;
            p->DumpTree(out, 0);
        }
    }
}

// =====================================================================================================

UpdateAssignmentNode::UpdateAssignmentNode(ColumnNode* col, ExpressionNode* expr)
{
    // TODO: ensure not null column.
    // TODO: ensure not null expression.
    this->col = col;
    this->expr = expr;
}

UpdateAssignmentNode::~UpdateAssignmentNode()
{
    delete this->col;
    delete this->expr;
}

void UpdateAssignmentNode::DumpTree(std::ostream& out, int indent) const
{
    out << std::string(indent, ' ');
    this->col->DumpTree(out, 0);
    out << " = ";
    this->expr->DumpTree(out, 0);
}
