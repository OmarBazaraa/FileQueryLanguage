#pragma once

#include <string>

#include "Common/Exceptions/BaseException.h"

namespace FQL
{
    class BadArgumentException : public BaseException
    {
    protected:
        std::string parameter;
        std::string value;

    public:
        BadArgumentException(const std::string& parameter, const std::string& value, const std::string& moreDetails)
            : BaseException("Parameter '" + parameter + "' value '" + value + "'  is invalid. " + moreDetails + ".")
        {
            this->parameter = parameter;
            this->value = value;
        }

        BadArgumentException(const std::string& parameter, const std::string& moreDetails)
            : BaseException("Parameter " + parameter + " value is invalid. " + moreDetails + ".")
        {
            this->parameter = parameter;
        }

        const std::string& GetParameter() const
        {
            return this->parameter;
        }

        const std::string& GetValue() const
        {
            return this->value;
        }
    };
}
