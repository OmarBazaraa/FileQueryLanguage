#ifndef __BAD_ARGUMENT_EXCEPTION_H_
#define __BAD_ARGUMENT_EXCEPTION_H_

#include <string>

#include "BaseException.h"

namespace FQL
{
    class BadArgumentException : public BaseException
    {
    private:
        std::string parameter;
        std::string value;

    public:
        BadArgumentException(std::string paramemer, std::string value, std::string moreDetails)
            : BaseException("Parameter '" + parameter + "' value '" + value + "'  is invalid. " + moreDetails + ".")
        {
            this->parameter = parameter;
            this->value = value;
        }

        BadArgumentException(std::string paramemer, std::string moreDetails)
            : BaseException("Parameter " + parameter + " value is invalid. " + moreDetails + ".")
        {
            this->parameter = parameter;
        }

        std::string GetParameter() const
        {
            return this->parameter;
        }

        std::string GetValue() const
        {
            return this->value;
        }
    };
}

#endif
