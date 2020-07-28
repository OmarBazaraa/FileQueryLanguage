#include <iostream>

#include "ValueNode.h"

using namespace FQL;

ValueNode::ValueNode(DataType type, const char *value)
{
    this->constant = true;
    this->type = type;
    this->value = value;
}

std::string ValueNode::GetValue() const
{
    return this->value;
}

void ValueNode::DumpTree(std::ostream &out, int indent) const
{
    out << std::string(indent, ' ') << this->value;
}
