#include "Parsers/Tree/Expressions/ExpressionNode.h"

using namespace FQL;

DataType ExpressionNode::GetDataType() const
{
    return this->type;
}

bool ExpressionNode::IsConstant() const
{
    return this->constant;
}
