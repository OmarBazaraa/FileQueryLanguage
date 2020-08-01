#pragma once

#include <Parsers/Tree/Clauses/ClauseNode.h>
#include <Parsers/Tree/Expressions/ExpressionNode.h>

namespace FQL
{
    class WhereNode : public ClauseNode
    {
    protected:
        ExpressionNode* cond = NULL;

    public:
        WhereNode(ExpressionNode* cond);

        virtual ~WhereNode();

        virtual void DumpTree(std::ostream& out, int indent = 0) const;
    };
}
