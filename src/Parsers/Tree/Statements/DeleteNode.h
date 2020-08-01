#pragma once

#include <string>
#include <vector>

#include <Parsers/Tree/Clauses/GroupByNode.h>
#include <Parsers/Tree/Clauses/HavingNode.h>
#include <Parsers/Tree/Clauses/LimitNode.h>
#include <Parsers/Tree/Clauses/OrderByNode.h>
#include <Parsers/Tree/Clauses/WhereNode.h>
#include <Parsers/Tree/DirectoryNode.h>
#include <Parsers/Tree/Statements/StatementNode.h>

namespace FQL
{
    class DeleteNode : public StatementNode
    {
    protected:
        DirectoryNode* dir = NULL;
        std::vector<ClauseNode*> clauses;

    public:
        DeleteNode(DirectoryNode* dir);

        DeleteNode(DirectoryNode* dir, const std::vector<ClauseNode*>& clauses);

        virtual ~DeleteNode();

        virtual bool Execute();

        virtual void DumpTree(std::ostream& out, int indent = 0) const;
    };
}
