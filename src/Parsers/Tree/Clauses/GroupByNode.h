#pragma once

#include <vector>

#include "Parsers/Tree/Clauses/ClauseNode.h"
#include "Parsers/Tree/SortRuleNode.h"

namespace FQL
{
    class GroupByNode : public ClauseNode
    {
    protected:
        std::vector<SortRuleNode*> rules;

    public:
        GroupByNode(std::vector<SortRuleNode*>& rules);

        virtual ~GroupByNode();

        virtual void DumpTree(std::ostream& out, int indent = 0) const;
    };
}
