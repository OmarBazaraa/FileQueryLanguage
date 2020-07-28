#include "ExpressionNode.h"

using namespace FileManager;

bool ExpressionNode::IsConstant() const
{
    return this->constant;
}

DataType ExpressionNode::GetDataType() const
{
    return this->type;
}
