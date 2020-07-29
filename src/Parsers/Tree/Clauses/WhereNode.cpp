#include "WhereNode.h"

using namespace FQL;

WhereNode::WhereNode(ExpressionNode *cond)
{
    // TODO: ensure not null condition.
    this->cond = cond;
}

WhereNode::~WhereNode()
{
    delete this->cond;
}

void WhereNode::DumpTree(std::ostream &out, int indent) const
{
    out << std::string(indent, ' ');
    out << "WHERE ";
    this->cond->DumpTree(out, 0);
}
