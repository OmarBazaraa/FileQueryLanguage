#include "TableRow.h"

using namespace FQL;

TableRow::TableRow()
    : values()
{
}

TableRow::TableRow(const std::map<std::string, std::string> &values)
    : values(values)
{
}

std::string TableRow::GetValue(const std::string &key) const
{
    return this->values.at(key);
}

void TableRow::UpdateValue(const std::string &key, const std::string &value)
{
    this->values[key] = value;
}
