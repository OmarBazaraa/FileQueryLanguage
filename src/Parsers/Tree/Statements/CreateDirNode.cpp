#include "CreateDirNode.h"
#include "../../../Common/Exceptions/DirectoryExistingException.h"

using namespace FileManager;

CreateDirNode::CreateDirNode(const char* dir, bool createIfNotExists) : CreateDirNode(std::string(dir), createIfNotExists) {

}

CreateDirNode::CreateDirNode(const std::string& dir, bool createIfNotExists) {
    this->dir = dir;
    this->createIfNotExists = createIfNotExists;
}

bool CreateDirNode::execute() {
    if (!this->createIfNotExists && fs::exists(this->dir)) {
        throw new DirectoryExistingException(this->dir);
    }

    return fs::create_directory(this->dir);
}

void CreateDirNode::dumpTree(std::ostream& out, int indent) const {

}
