#ifndef __GROUP_BY_NODE_H_
#define __GROUP_BY_NODE_H_

#include <vector>

#include "ClauseNode.h"
#include "SortRuleNode.h"

namespace FQL
{
    class GroupByNode : public ClauseNode
    {
    protected:
        std::vector<SortRuleNode *> rules;

    public:
        GroupByNode(std::vector<SortRuleNode *> &rules);

        virtual ~GroupByNode();

        virtual void DumpTree(std::ostream &out, int indent = 0) const;
    };
}

#endif
