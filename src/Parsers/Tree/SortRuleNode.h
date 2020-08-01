#ifndef __SORT_RULE_NODE_H_
#define __SORT_RULE_NODE_H_

#include <Common/Enums.h>
#include <Parsers/Tree/Expressions/ExpressionNode.h>

namespace FQL
{
    class SortRuleNode : public BaseNode
    {
    protected:
        SortDirection dir = SORT_ASC;
        ExpressionNode* expr = NULL;

    public:
        SortRuleNode(ExpressionNode* expr, SortDirection dir = SORT_ASC);

        virtual ~SortRuleNode();

        virtual SortDirection GetDirection() const;

        virtual const ExpressionNode* GetExpression() const;

        virtual void DumpTree(std::ostream& out, int indent = 0) const;
    };
}

#endif
