#ifndef __VALUE_NODE_H_
#define __VALUE_NODE_H_

#include <string>

#include "../ExpressionNode.h"

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

#endif
