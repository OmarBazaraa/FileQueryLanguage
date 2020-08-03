#pragma once

#include <string>
#include <vector>

#include "Parsers/Tree/Clauses/GroupByNode.h"
#include "Parsers/Tree/Clauses/HavingNode.h"
#include "Parsers/Tree/Clauses/LimitNode.h"
#include "Parsers/Tree/Clauses/OrderByNode.h"
#include "Parsers/Tree/Clauses/WhereNode.h"
#include "Parsers/Tree/DirectoryNode.h"
#include "Parsers/Tree/Expressions/ColumnNode.h"
#include "Parsers/Tree/Expressions/ExpressionNode.h"
#include "Parsers/Tree/Statements/StatementNode.h"

namespace FQL
{
    class UpdateAssignmentNode;

    class UpdateNode : public StatementNode
    {
    protected:
        DirectoryNode* dir = NULL;
        std::vector<UpdateAssignmentNode*> assignments;
        std::vector<ClauseNode*> clauses;

    public:
        UpdateNode(DirectoryNode* dir, const std::vector<UpdateAssignmentNode*>& assignments);

        UpdateNode(DirectoryNode* dir, const std::vector<UpdateAssignmentNode*>& assignments, const std::vector<ClauseNode*>& clauses);

        virtual ~UpdateNode();

        virtual bool Execute();

        virtual void DumpTree(std::ostream& out, int indent = 0) const;
    };

    class UpdateAssignmentNode : public BaseNode
    {
    protected:
        ColumnNode* col;
        ExpressionNode* expr;

    public:
        UpdateAssignmentNode(ColumnNode* col, ExpressionNode* expr);

        virtual ~UpdateAssignmentNode();

        virtual void DumpTree(std::ostream& out, int indent = 0) const;
    };
}
