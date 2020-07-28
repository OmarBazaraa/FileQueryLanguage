#include "ExpressionNode.h"

using namespace FileManager;

bool ExpressionNode::isConstant() const {
    return this->constant;
}
        
DataType ExpressionNode::getDataType() const {
    return this->type;
}
