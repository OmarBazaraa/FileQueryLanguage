#pragma once

#include "Parsers/Tree/BaseNode.h"

namespace FQL
{
    class ClauseNode : public BaseNode
    {
    public:
        ClauseNode() = default;

        virtual ~ClauseNode() = default;
    };
}
