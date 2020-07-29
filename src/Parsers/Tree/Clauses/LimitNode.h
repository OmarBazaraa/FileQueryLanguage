#ifndef __LIMIT_NODE_H_
#define __LIMIT_NODE_H_

#include "ClauseNode.h"
#include "../Expressions/ExpressionNode.h"

namespace FQL
{
    class LimitNode : public ClauseNode
    {
    protected:
        ExpressionNode *limitExpr = NULL;
        ExpressionNode *offsetExpr = NULL;

    public:
        LimitNode(ExpressionNode *limitExpr);

        LimitNode(ExpressionNode *limitExpr, ExpressionNode *offsetExpr);

        virtual ~LimitNode();

        virtual void DumpTree(std::ostream &out, int indent = 0) const;
    };
}

#endif
