#include "FileTableRow.h"

using namespace FQL;

FileTableRow::FileTableRow()
    :values()
{
}

FileTableRow::FileTableRow(std::map<std::string, std::string> values)
    : values(values)
{
}

std::string FileTableRow::GetValue(std::string key) const
{
    return this->values.at(key);
}

void FileTableRow::UpdateValue(std::string key, std::string value)
{
    this->values[key] = value;
}