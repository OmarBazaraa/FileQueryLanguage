#ifndef __FIELD_EXCEPTION_H_
#define __FIELD_EXCEPTION_H_

#include <string>

#include "BaseException.h"

namespace FQL
{
    class FieldException : public BaseException
    {
    protected:
        std::string value;
        std::string field;

    public:
        FieldException(const std::string &field, const std::string &message)
            : BaseException(message)
        {
            this->field = field;
        }

        FieldException(const std::string &field, const std::string &value, const std::string &message)
            : BaseException(message)
        {
            this->field = field;
            this->value = value;
        }

        std::string GetField() const
        {
            return this->field;
        }

        std::string GetValue() const
        {
            return this->value;
        }
    };
}

#endif
