#pragma once

#include "Parsers/Tree/Expressions/ExpressionNode.h"

namespace FQL
{
    class ValueNode : public ExpressionNode
    {
    public:
        ValueNode()
        {
            this->constant = true;
        }

        virtual ~ValueNode() = default;
    };
}
