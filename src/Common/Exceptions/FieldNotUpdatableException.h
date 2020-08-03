#pragma once

#include "Common/Exceptions/FieldException.h"

namespace FQL
{
    class FieldNotUpdatableException : public FieldException
    {
    public:
        FieldNotUpdatableException(const std::string& field)
            : FieldException(field, "Field '" + field + "' cannot be updated.")
        {
        }
    };
}
