#pragma once

#include <vector>

#include "Parsers/Tree/Clauses/ClauseNode.h"
#include "Parsers/Tree/SortRuleNode.h"

namespace FQL
{
    class OrderByNode : public ClauseNode
    {
    protected:
        std::vector<SortRuleNode*> rules;

    public:
        OrderByNode(std::vector<SortRuleNode*>& rules);

        virtual ~OrderByNode();

        virtual void DumpTree(std::ostream& out, int indent = 0) const;
    };
}
