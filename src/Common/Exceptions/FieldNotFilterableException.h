#pragma once

#include <Common/Exceptions/FieldException.h>

namespace FQL
{
    class FieldNotFilterableException : public FieldException
    {
    public:
        FieldNotFilterableException(const std::string& field)
            : FieldException(field, "Field '" + field + "' cannot is not filterable.")
        {
        }
    };
}
