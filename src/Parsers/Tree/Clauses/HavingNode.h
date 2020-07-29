#ifndef __HAVING_NODE_H_
#define __HAVING_NODE_H_

#include "ClauseNode.h"
#include "../Expressions/ExpressionNode.h"

namespace FQL
{
    class HavingNode : public ClauseNode
    {
    protected:
        ExpressionNode *cond;

    public:
        HavingNode(ExpressionNode *cond);

        virtual ~HavingNode();

        virtual void DumpTree(std::ostream &out, int indent = 0) const;
    };
}

#endif
