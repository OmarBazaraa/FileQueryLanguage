#include "ColumnNode.h"

using namespace FileManager;

ColumnNode::ColumnNode(const char* name) {
    this->constant = false;

    // TODO: how and when to know the data type?
    this->type = type;

    // TODO: should we support only a whitelist of column names?
    this->name = name;
}

std::string ColumnNode::getName() const {
    return this->name;
}

void ColumnNode::dumpTree(std::ostream& out, int indent = 0) const {

}
