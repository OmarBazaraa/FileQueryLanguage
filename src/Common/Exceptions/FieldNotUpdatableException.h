#ifndef __FIELD_NOT_UPDATABLE_EXCEPTION_H_
#define __FIELD_NOT_UPDATABLE_EXCEPTION_H_

#include <string>

#include <Common/Exceptions/FieldException.h>

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

#endif
