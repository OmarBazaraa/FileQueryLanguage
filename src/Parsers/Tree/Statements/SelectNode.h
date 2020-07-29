#ifndef __SELECT_NODE_H_
#define __SELECT_NODE_H_

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

namespace FQL
{
    class SelectExpressionNode;

    class SelectNode : public StatementNode
    {
    protected:
        DirectoryNode *dir = NULL;
        std::vector<SelectExpressionNode *> expressions;
        std::vector<ClauseNode *> clauses;
        int options = 0;

    public:
        SelectNode(const std::vector<SelectExpressionNode *> &expressions, int options = 0);

        SelectNode(DirectoryNode *dir, const std::vector<SelectExpressionNode *> &expressions, const std::vector<ClauseNode *> &clauses, int options = 0);

        virtual ~SelectNode();

        virtual bool Execute();

        virtual void DumpTree(std::ostream &out, int indent = 0) const;
    };

    class SelectExpressionNode : public BaseNode
    {
    protected:
        std::string alias;
        ExpressionNode *expr;

    public:
        SelectExpressionNode(ExpressionNode *expr);

        SelectExpressionNode(ExpressionNode *expr, const std::string &alias);

        virtual ~SelectExpressionNode();

        virtual void DumpTree(std::ostream &out, int indent = 0) const;
    };

    enum SelectOptions
    {
        SELECT_DEFAULT = 0,
        SELECT_DISTINCT = 1
    };
}

#endif
