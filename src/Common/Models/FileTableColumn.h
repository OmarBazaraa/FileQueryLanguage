#ifndef __FILE_TABLE_COLUMN_H_
#define __FILE_TABLE_COLUMN_H_

#include <string>

#include "../Enums/DataTypes.h"

namespace FQL
{
    class FileTableColumn
    {
    private:
        std::string name;

        DataType type;

    public:
        FileTableColumn(std::string name, DataType type);

        std::string GetName() const;
        DataType GetType() const;
    };
}

#endif
