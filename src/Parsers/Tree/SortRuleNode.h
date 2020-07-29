#ifndef __SORT_RULE_NODE_H_
#define __SORT_RULE_NODE_H_

#include "Expressions/ExpressionNode.h"
#include "../../Common/Enums/SortDirection.h"

namespace FQL
{
    class SortRuleNode : public BaseNode
    {
    protected:
        SortDirection dir = SORT_ASC;
        ExpressionNode *expr;

    public:
        SortRuleNode(ExpressionNode *expr);

        SortRuleNode(ExpressionNode *expr, SortDirection dir);

        virtual ~SortRuleNode();

        virtual void DumpTree(std::ostream &out, int indent = 0) const;
    };
}

#endif
