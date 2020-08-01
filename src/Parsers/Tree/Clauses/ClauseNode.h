#ifndef __CLAUSE_NODE_H_
#define __CLAUSE_NODE_H_

#include <Parsers/Tree/BaseNode.h>

namespace FQL
{
    class ClauseNode : public BaseNode
    {
    public:
        ClauseNode() = default;

        virtual ~ClauseNode() = default;
    };
}

#endif
