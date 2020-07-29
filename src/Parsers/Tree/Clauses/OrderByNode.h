#ifndef __ORDER_BY_NODE_H_
#define __ORDER_BY_NODE_H_

#include <vector>

#include "ClauseNode.h"
#include "SortRuleNode.h"

namespace FQL
{
    class OrderBy : public ClauseNode
    {
    protected:
        std::vector<SortRuleNode *> rules;

    public:
        OrderBy(std::vector<SortRuleNode *> &rules);

        virtual ~OrderBy();

        virtual void DumpTree(std::ostream &out, int indent = 0) const;
    };
}

#endif
