#ifndef __COLUMN_NODE_H_
#define __COLUMN_NODE_H_

#include <string>

#include "ValueNode.h"

namespace FileManager {

    class ColumnNode : public ExpressionNode {
    protected:

        // TODO: use custom type to support both cases: `Col1`, `Table1.Col1`.
        std::string name;
        
    public:

        ColumnNode(const char* name);

        virtual ~ColumnNode() = default;

        std::string getName() const;

        virtual void dumpTree(std::ostream& out, int indent = 0) const;
    };
}

#endif
