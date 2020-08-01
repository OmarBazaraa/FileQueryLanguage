#pragma once

#include <string>

#include <Parsers/Tree/DirectoryNode.h>
#include <Parsers/Tree/Statements/StatementNode.h>

namespace FQL
{
    class DropNode : public StatementNode
    {
    protected:
        bool dropIfExists = false;
        DirectoryNode* dir = NULL;

    public:
        DropNode(DirectoryNode* dir, bool dropIfExists = false);

        virtual ~DropNode() = default;

        virtual bool Execute();

        virtual void DumpTree(std::ostream& out, int indent = 0) const;
    };
}
