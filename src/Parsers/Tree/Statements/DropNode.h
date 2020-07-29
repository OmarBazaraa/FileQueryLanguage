#ifndef __DROP_NODE_H_
#define __DROP_NODE_H_

#include <string>

#include "StatementNode.h"
#include "../DirectoryNode.h"

namespace FQL
{
    class DropNode : public StatementNode
    {
    protected:
        bool dropIfExists = false;
        DirectoryNode *dir = NULL;

    public:
        DropNode(DirectoryNode *dir, bool dropIfExists = false);

        virtual ~DropNode() = default;

        virtual bool Execute();

        virtual void DumpTree(std::ostream &out, int indent = 0) const;
    };
}

#endif
