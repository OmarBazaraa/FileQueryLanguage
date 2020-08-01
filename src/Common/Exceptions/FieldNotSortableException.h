#pragma once

#include <Common/Exceptions/FieldException.h>

namespace FQL
{
    class FieldNotSortableException : public FieldException
    {
    public:
        FieldNotSortableException(const std::string& field)
            : FieldException(field, "Field '" + field + "' is not sortable.")
        {
        }
    };
}
