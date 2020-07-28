#ifndef __CREATE_DIR_NODE_H_
#define __CREATE_DIR_NODE_H_

#include <string>

#include "StatementNode.h"

namespace FQL
{
    class CreateDirNode : public StatementNode
    {
    protected:
        // TODO: change to custom type.
        std::string dir;

        bool createIfNotExists = false;

    public:
        CreateDirNode(const std::string &dir, bool createIfNotExists = false);

        virtual ~CreateDirNode() = default;

        virtual bool Execute();

        virtual void DumpTree(std::ostream &out, int indent = 0) const;
    };
}

#endif
