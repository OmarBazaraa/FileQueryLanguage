#ifndef __FIELD_EXCEPTION_H_
#define __FIELD_EXCEPTION_H_

#include <string>

#include "BaseException.h"

namespace FileManager
{
    class FieldException : public BaseException
    {
    private:
        std::string value;
        std::string field;

    public:
        FieldException(std::string field, std::string message)
            : BaseException(message)
        {
            this->field = field;
        }

        FieldException(std::string field, std::string value, std::string message)
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
