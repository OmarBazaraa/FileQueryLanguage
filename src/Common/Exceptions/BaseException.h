#ifndef __BASE_EXCEPTION_H_
#define __BASE_EXCEPTION_H_

#include <string>

namespace FQL
{
    class BaseException
    {
    protected:
        std::string message;

    public:
        BaseException(const std::string& message)
        {
            this->message = message;
        }

        const std::string& GetMessage() const
        {
            return this->message;
        }
    };
}

#endif
