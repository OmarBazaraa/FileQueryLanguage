#ifndef __FIELD_NOT_FILTERABLE_EXCEPTION_H_
#define __FIELD_NOT_FILTERABLE_EXCEPTION_H_

#include <string>

#include "FieldException.h"

namespace FQL
{
    class FieldNotFilterableException : public FieldException
    {
    public:
        FieldNotFilterableException(const std::string &field)
            : FieldException(field, "Field '" + field + "' cannot be used in the where statemet.")
        {
        }
    };
}

#endif
