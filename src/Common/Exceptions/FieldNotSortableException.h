#ifndef __FIELD_NOT_SORTABLE_EXCEPTION_H_
#define __FIELD_NOT_SORTABLE_EXCEPTION_H_

#include <string>

#include "FieldException.h"

namespace FileManager
{
    class FieldNotSortableException : public FieldException
    {
    public:
        FieldNotSortableException(std::string field)
            : FieldException(field, "Field '" + field + "' cannot be used in the order by statemet.")
        {
        }
    };
}

#endif
