#include "ValueNode.h"

using namespace FileManager;

ValueNode::ValueNode(DataType type, const char* value) {
    this->constant = true;
    this->type = type;
    this->value = value;
}

std::string ValueNode::getValue() const {
    return this->value;
}

void ValueNode::dumpTree(std::ostream& out, int indent = 0) const {

}
