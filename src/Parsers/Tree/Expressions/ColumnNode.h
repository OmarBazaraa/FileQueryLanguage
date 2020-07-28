#ifndef __COLUMN_NODE_H_
#define __COLUMN_NODE_H_

#include <string>

#include "ValueNode.h"

namespace FQL
{
    class ColumnNode : public ExpressionNode
    {
    protected:
        // TODO: use custom type to support both cases: `Col1`, `Table1.Col1`.
        std::string name;

    public:
        ColumnNode(const char *name);

        virtual ~ColumnNode() = default;

        std::string GetName() const;

        virtual void DumpTree(std::ostream &out, int indent = 0) const;
    };
}

#endif
