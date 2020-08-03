#pragma once

#include "Common/Exceptions/FieldException.h"

namespace FQL
{
    class FieldNotSupportedException : public FieldException
    {
    public:
        FieldNotSupportedException(const std::string& field)
            : FieldException(field, "Field '" + field + "' is not supported.")
        {
        }
    };
}
