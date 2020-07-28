#include "HavingNode.h"

using namespace FQL;

HavingNode::HavingNode(ExpressionNode *cond)
{
    // TODO: ensure not null condition.
    this->cond = cond;
}

HavingNode::~HavingNode()
{
    delete this->cond;
}

void HavingNode::DumpTree(std::ostream &out, int indent) const
{
    out << std::string(indent, ' ');
    out << "HAVING ";
    this->cond->DumpTree(out, 0);
}
