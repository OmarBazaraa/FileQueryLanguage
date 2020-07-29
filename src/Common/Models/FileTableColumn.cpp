#include "FileTableColumn.h"

using namespace FQL;

FileTableColumn::FileTableColumn(std::string name, DataType type)
    : name(name), type(type)
{
}

std::string FileTableColumn::GetName() const
{
    return this->name;
}

DataType FileTableColumn::GetType() const
{
    return this->type;
}
