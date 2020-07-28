#include "CreateDirNode.h"

using namespace FileManager;

CreateDirNode::CreateDirNode(const char* dir, bool createIfNotExists) : CreateDirNode(std::string(dir), createIfNotExists) {

}

CreateDirNode::CreateDirNode(const std::string& dir, bool createIfNotExists) {
    this->dir = dir;
    this->createIfNotExists = createIfNotExists;
}

bool CreateDirNode::execute() const {
    return false;
}

void CreateDirNode::dumpTree(std::ostream& out, int indent) const {

}
