#pragma once

#include <Parsers/Tree/BaseNode.h>

namespace FQL
{
    class StatementNode : public BaseNode
    {
    public:
        StatementNode() = default;

        virtual ~StatementNode() = default;

        virtual bool Execute() = 0;
    };
}
