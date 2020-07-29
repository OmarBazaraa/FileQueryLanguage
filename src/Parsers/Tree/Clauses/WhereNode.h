#ifndef __WHERE_NODE_H_
#define __WHERE_NODE_H_

#include "ClauseNode.h"
#include "../Expressions/ExpressionNode.h"

namespace FQL
{
    class WhereNode : public ClauseNode
    {
    protected:
        ExpressionNode *cond = NULL;

    public:
        WhereNode(ExpressionNode *cond);

        virtual ~WhereNode();

        virtual void DumpTree(std::ostream &out, int indent = 0) const;
    };
}

#endif
