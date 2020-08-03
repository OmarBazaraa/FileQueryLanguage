#pragma once

#include <string>

#include "Common/Enums.h"

namespace FQL
{
    class TableColumn
    {
    private:
        std::string name;

        DataType type;

    public:
        TableColumn(const std::string& name, DataType type);

        std::string GetName() const;
        
        DataType GetType() const;
    };
}
