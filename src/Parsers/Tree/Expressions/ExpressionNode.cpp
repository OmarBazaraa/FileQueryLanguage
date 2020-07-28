#include "ExpressionNode.h"

using namespace FQL;

bool ExpressionNode::IsConstant() const
{
    return this->constant;
}

DataType ExpressionNode::GetDataType() const
{
    return this->type;
}
