#ifndef __VALUE_NODE_H_
#define __VALUE_NODE_H_

#include <string>

#include "ExpressionNode.h"

namespace FQL
{
    class ValueNode : public ExpressionNode
    {
    protected:
        // TODO: add custom classes for the supported types.
        // TODO: add base class for all our the supported types.
        // TODO: provide custom operators in these types.
        std::string value;

    public:
        ValueNode(DataType type, const char *value);

        virtual ~ValueNode() = default;

        std::string GetValue() const;

        virtual void DumpTree(std::ostream &out, int indent = 0) const;
    };
}

#endif
