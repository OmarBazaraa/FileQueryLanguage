#pragma once

#include <string>

namespace FQL
{
    class Loader
    {
    protected:
        std::string dir;

    public:
        Loader(const std::string& dir);

        virtual ~Loader() = default;

        virtual Table* Load();
    };
}
