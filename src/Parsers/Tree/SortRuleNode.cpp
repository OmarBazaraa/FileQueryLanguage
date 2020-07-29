#include "SortRuleNode.h"

using namespace FQL;

SortRuleNode::SortRuleNode(ExpressionNode *expr)
{
    // TODO: ensure not null expression.
    // TODO: ensure constant expression.
    this->expr = expr;
}

SortRuleNode::SortRuleNode(ExpressionNode *expr, SortDirection dir)
    : SortRuleNode(expr)
{
    this->dir = dir;
}

SortRuleNode::~SortRuleNode()
{
    delete this->expr;
}

void SortRuleNode::DumpTree(std::ostream &out, int indent) const
{
    out << std::string(indent, ' ');
    this->expr->DumpTree(out, indent);
    out << (this->dir == SORT_ASC ? " ASC" : " DESC");
}
