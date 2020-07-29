#ifndef __FIELD_NOT_UPDATABLE_EXCEPTION_H_
#define __FIELD_NOT_UPDATABLE_EXCEPTION_H_

#include <string>

#include "FieldException.h"

namespace FileManager
{
    class FieldNotUpdatableException : public FieldException
    {
    public:
        FieldNotUpdatableException(std::string field)
            : FieldException(field, "Field '" + field + "' cannot be updated.")
        {
        }
    };
}

#endif
