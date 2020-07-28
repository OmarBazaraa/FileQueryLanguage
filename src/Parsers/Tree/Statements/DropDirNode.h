#ifndef __DROP_DIR_NODE_H_
#define __DROP_DIR_NODE_H_

#include <string>

#include "StatementNode.h"

namespace FQL
{
    class DropDirNode : public StatementNode
    {
    protected:
        // TODO: change to custom type.
        std::string dir;

        bool dropIfExists = false;

    public:
        DropDirNode(const std::string &dir, bool dropIfExists = false);

        virtual ~DropDirNode() = default;

        virtual bool Execute();

        virtual void DumpTree(std::ostream &out, int indent = 0) const;
    };
}

#endif
