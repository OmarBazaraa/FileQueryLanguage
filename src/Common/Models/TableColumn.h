#ifndef __TABLE_COLUMN_H_
#define __TABLE_COLUMN_H_

#include <string>

#include "../Enums/DataTypes.h"

namespace FQL
{
    class TableColumn
    {
    private:
        std::string name;

        DataType type;

    public:
        TableColumn(const std::string &name, DataType type);

        std::string GetName() const;
        DataType GetType() const;
    };
}

#endif
