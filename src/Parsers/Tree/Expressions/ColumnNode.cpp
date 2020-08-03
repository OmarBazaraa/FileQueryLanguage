#include "Parsers/Tree/Expressions/ColumnNode.h"

using namespace FQL;

ColumnNode::ColumnNode(const std::string& colName)
{
    this->colName = colName;
}

ColumnNode::ColumnNode(const std::string& tableName, const std::string& colName)
    : ColumnNode(colName)
{
    this->tableName = tableName;
}

void ColumnNode::DumpTree(std::ostream& out, int indent) const
{
    out << std::string(indent, ' ');
    out << "`";
    out << (this->tableName.size() > 0 ? this->tableName + "." : "") << this->colName;
    out << "`";
}
