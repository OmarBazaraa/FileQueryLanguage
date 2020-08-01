#pragma once

#include <iostream>

namespace FQL
{
    class BaseNode
    {
    public:
        BaseNode() = default;

        virtual ~BaseNode() = default;

        virtual void DumpTree(std::ostream& out, int indent = 0) const = 0;
    };
}
