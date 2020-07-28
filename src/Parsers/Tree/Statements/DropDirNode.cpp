#include "DropDirNode.h"

using namespace FileManager;

DropDirNode::DropDirNode(const char* dir, bool dropIfExists) : DropDirNode(std::string(dir), dropIfExists) {

}

DropDirNode::DropDirNode(const std::string& dir, bool dropIfExists) {
    this->dir = dir;
    this->dropIfExists = dropIfExists;
}

bool DropDirNode::execute() const {
    return false;
}

void DropDirNode::dumpTree(std::ostream& out, int indent) const {

}
