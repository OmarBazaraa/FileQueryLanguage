#ifndef __FIELD_NOT_SORTABLE_EXCEPTION_H_
#define __FIELD_NOT_SORTABLE_EXCEPTION_H_

#include <string>

#include "FieldException.h"

namespace FQL
{
    class FieldNotSortableException : public FieldException
    {
    public:
        FieldNotSortableException(const std::string &field)
            : FieldException(field, "Field '" + field + "' cannot be used in the order by statemet.")
        {
        }
    };
}

#endif
