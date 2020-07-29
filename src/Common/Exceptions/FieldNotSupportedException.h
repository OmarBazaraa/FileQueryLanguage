#ifndef __FIELD_NOT_SUPPORTED_EXCEPTION_H_
#define __FIELD_NOT_SUPPORTED_EXCEPTION_H_

#include <string>

#include "FieldException.h"

namespace FQL
{
    class FieldNotSupportedException : public FieldException
    {
    public:
        FieldNotSupportedException(const std::string &field)
            : FieldException(field, "Field '" + field + "' is not supported.")
        {
        }
    };
}

#endif
