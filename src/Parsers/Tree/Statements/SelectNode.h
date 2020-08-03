#pragma once

#include <string>
#include <vector>

#include "Parsers/Tree/Clauses/GroupByNode.h"
#include "Parsers/Tree/Clauses/HavingNode.h"
#include "Parsers/Tree/Clauses/LimitNode.h"
#include "Parsers/Tree/Clauses/OrderByNode.h"
#include "Parsers/Tree/Clauses/WhereNode.h"
#include "Parsers/Tree/DirectoryNode.h"
#include "Parsers/Tree/Expressions/ExpressionNode.h"
#include "Parsers/Tree/Statements/StatementNode.h"

namespace FQL
{
    class SelectExpressionNode;

    class SelectNode : public StatementNode
    {
    protected:
        DirectoryNode* dir = NULL;
        std::vector<SelectExpressionNode*> expressions;
        std::vector<ClauseNode*> clauses;
        int options = 0;

    public:
        SelectNode(const std::vector<SelectExpressionNode*>& expressions, int options = 0);

        SelectNode(DirectoryNode* dir, const std::vector<SelectExpressionNode*>& expressions, const std::vector<ClauseNode*>& clauses, int options = 0);

        virtual ~SelectNode();

        virtual bool Execute();

        virtual void DumpTree(std::ostream& out, int indent = 0) const;
    };

    class SelectExpressionNode : public BaseNode
    {
    protected:
        std::string alias;
        ExpressionNode* expr;

    public:
        SelectExpressionNode(ExpressionNode* expr);

        SelectExpressionNode(ExpressionNode* expr, const std::string& alias);

        virtual ~SelectExpressionNode();

        virtual void DumpTree(std::ostream& out, int indent = 0) const;
    };

    enum SelectOptions
    {
        SELECT_DEFAULT = 0,
        SELECT_DISTINCT = 1
    };
}
