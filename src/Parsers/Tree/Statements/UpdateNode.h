#ifndef __UPDATE_NODE_H_
#define __UPDATE_NODE_H_

#include <string>
#include <vector>

#include "StatementNode.h"
#include "../DirectoryNode.h"
#include "../Clauses/WhereNode.h"
#include "../Clauses/GroupByNode.h"
#include "../Clauses/HavingNode.h"
#include "../Clauses/OrderByNode.h"
#include "../Clauses/LimitNode.h"
#include "../Expressions/ExpressionNode.h"
#include "../Expressions/ColumnNode.h"

namespace FQL
{
    class UpdateAssignmentNode;

    class UpdateNode : public StatementNode
    {
    protected:
        DirectoryNode *dir = NULL;
        std::vector<UpdateAssignmentNode *> assignments;
        std::vector<ClauseNode *> clauses;

    public:
        UpdateNode(DirectoryNode *dir, const std::vector<UpdateAssignmentNode *> &assignments);

        UpdateNode(DirectoryNode *dir, const std::vector<UpdateAssignmentNode *> &assignments, const std::vector<ClauseNode *> &clauses);

        virtual ~UpdateNode();

        virtual bool Execute();

        virtual void DumpTree(std::ostream &out, int indent = 0) const;
    };

    class UpdateAssignmentNode : public BaseNode
    {
    protected:
        ColumnNode *col;
        ExpressionNode *expr;

    public:
        UpdateAssignmentNode(ColumnNode *col, ExpressionNode *expr);

        virtual ~UpdateAssignmentNode();

        virtual void DumpTree(std::ostream &out, int indent = 0) const;
    };
}

#endif
