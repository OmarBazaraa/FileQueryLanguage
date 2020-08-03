#include "TableColumn.h"

#include "Models/TableColumn.h"

using namespace FQL;

TableColumn::TableColumn(const std::string& name, DataType type)
    : name(name), type(type)
{
}

std::string TableColumn::GetName() const
{
    return this->name;
}

DataType TableColumn::GetType() const
{
    return this->type;
}
