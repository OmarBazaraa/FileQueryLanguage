#ifndef __DROP_NODE_H_
#define __DROP_NODE_H_

#include <string>

#include "StatementNode.h"

namespace FQL
{
    class DropNode : public StatementNode
    {
    protected:
        // TODO: change to custom type.
        const std::string dir;

        const bool dropIfExists = false;

    public:
        DropNode(const char *dir, bool dropIfExists = false);

        DropNode(const std::string &dir, bool dropIfExists = false);

        virtual ~DropNode() = default;

        virtual bool Execute();

        virtual void DumpTree(std::ostream &out, int indent = 0) const;
    };
}

#endif
