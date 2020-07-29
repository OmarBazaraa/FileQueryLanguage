#ifndef __DELETE_NODE_H_
#define __DELETE_NODE_H_

#include <string>
#include <vector>

#include "StatementNode.h"
#include "../DirectoryNode.h"
#include "../Clauses/WhereNode.h"
#include "../Clauses/GroupByNode.h"
#include "../Clauses/HavingNode.h"
#include "../Clauses/OrderByNode.h"
#include "../Clauses/LimitNode.h"

namespace FQL
{
    class DeleteNode : public StatementNode
    {
    protected:
        DirectoryNode *dir = NULL;
        std::vector<ClauseNode *> clauses;

    public:
        DeleteNode(DirectoryNode *dir);

        DeleteNode(DirectoryNode *dir, const std::vector<ClauseNode *> &clauses);

        virtual ~DeleteNode();

        virtual bool Execute();

        virtual void DumpTree(std::ostream &out, int indent = 0) const;
    };
}

#endif
