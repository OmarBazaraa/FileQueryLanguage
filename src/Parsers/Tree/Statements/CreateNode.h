#ifndef __CREATE_NODE_H_
#define __CREATE_NODE_H_

#include <string>

#include <Parsers/Tree/DirectoryNode.h>
#include <Parsers/Tree/Statements/StatementNode.h>

namespace FQL
{
    class CreateNode : public StatementNode
    {
    protected:
        bool createIfNotExists = false;
        DirectoryNode* dir = NULL;

    public:
        CreateNode(DirectoryNode* dir, bool createIfNotExists = false);

        virtual ~CreateNode() = default;

        virtual bool Execute();

        virtual void DumpTree(std::ostream& out, int indent = 0) const;
    };
}

#endif
