#ifndef __DROP_DIR_NODE_H_
#define __DROP_DIR_NODE_H_

#include <string>

#include "StatementNode.h"

namespace FileManager {

    class DropDirNode : public StatementNode {
    protected:

        // TODO: change to custom type.
        std::string dir;

        bool dropIfExists = false;

    public:

        DropDirNode(const char* dir, bool dropIfExists = false);

        DropDirNode(const std::string& dir, bool dropIfExists = false);

        virtual ~DropDirNode() = default;

        virtual bool execute() const;

        virtual void dumpTree(std::ostream& out, int indent = 0) const;
    };
}

#endif
