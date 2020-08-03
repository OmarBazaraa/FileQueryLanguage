#pragma once

#include "Parsers/Tree/Clauses/ClauseNode.h"
#include "Parsers/Tree/Expressions/ExpressionNode.h"

namespace FQL
{
    class LimitNode : public ClauseNode
    {
    protected:
        ExpressionNode* limitExpr = NULL;
        ExpressionNode* offsetExpr = NULL;

    public:
        LimitNode(ExpressionNode* limitExpr);

        LimitNode(ExpressionNode* limitExpr, ExpressionNode* offsetExpr);

        virtual ~LimitNode();

        virtual void DumpTree(std::ostream& out, int indent = 0) const;
    };
}
