#ifndef __COLUMN_NODE_H_
#define __COLUMN_NODE_H_

#include <string>

#include <Parsers/Tree/Expressions/ExpressionNode.h>

namespace FQL
{
    class ColumnNode : public ExpressionNode
    {
    protected:
        std::string colName;
        std::string tableName;

    public:
        ColumnNode(const std::string& colName);

        ColumnNode(const std::string& tableName, const std::string& colName);

        virtual ~ColumnNode() = default;

        virtual void DumpTree(std::ostream& out, int indent = 0) const;
    };
}

#endif
