#ifndef __LOADER_H_
#define __LOADER_H_

#include <string>

namespace FQL
{
    class Loader
    {
    protected:
        std::string dir;

    public:
        Loader(const std::string &dir);

        virtual ~Loader() = default;

        virtual Table *Load();
    };
}

#endif
