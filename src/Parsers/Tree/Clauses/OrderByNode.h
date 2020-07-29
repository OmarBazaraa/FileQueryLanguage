#ifndef __ORDER_BY_NODE_H_
#define __ORDER_BY_NODE_H_

#include <vector>

#include "ClauseNode.h"
#include "../SortRuleNode.h"

namespace FQL
{
    class OrderByNode : public ClauseNode
    {
    protected:
        std::vector<SortRuleNode *> rules;

    public:
        OrderByNode(std::vector<SortRuleNode *> &rules);

        virtual ~OrderByNode();

        virtual void DumpTree(std::ostream &out, int indent = 0) const;
    };
}

#endif
