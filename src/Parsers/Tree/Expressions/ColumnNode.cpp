#include "ColumnNode.h"

using namespace FQL;

ColumnNode::ColumnNode(const std::string &colName)
{
    this->constant = false;
    this->type = TYPE_UNKNOWN;
    this->colName = colName;
}

ColumnNode::ColumnNode(const std::string &tableName, const std::string &colName)
{
    this->constant = false;
    this->type = TYPE_UNKNOWN;
    this->tableName = tableName;
    this->colName = colName;
}

void ColumnNode::DumpTree(std::ostream &out, int indent) const
{
    out << std::string(indent, ' ');
    out << "`";

    if (this->tableName.empty())
    {
        out << this->colName;
    }
    else
    {
        out << this->tableName << "." << this->colName;
    }
    
    out << "`";
}
