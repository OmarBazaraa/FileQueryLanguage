#include "LimitNode.h"

using namespace FQL;

LimitNode::LimitNode(ExpressionNode *limitExpr)
{
    // TODO: ensure not null limit expression.
    // TODO: ensure constant expressions.
    this->limitExpr = limitExpr;
}

LimitNode::LimitNode(ExpressionNode *limitExpr, ExpressionNode *offsetExpr)
    : LimitNode(limitExpr)
{
    // TODO: ensure constant expressions.
    this->offsetExpr = offsetExpr;
}

LimitNode::~LimitNode()
{
    delete this->limitExpr;

    if (this->offsetExpr != NULL)
    {
        delete this->offsetExpr;
    }
}

void LimitNode::DumpTree(std::ostream &out, int indent) const
{
    out << std::string(indent, ' ');
    out << "LIMIT ";
    this->limitExpr->DumpTree(out, 0);

    if (this->offsetExpr != NULL)
    {
        out << std::endl;
        out << std::string(indent, ' ');
        out << "OFFSET ";
        this->offsetExpr->DumpTree(out, 0);
    }
}
