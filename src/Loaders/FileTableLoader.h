#pragma once

#include <Loaders/Loader.h>
#include <Models/Table.h>

namespace FQL
{
    class FileTableLoader : public Loader
    {
    private:
        const std::string NAME = "name";           // Includes extension.
        const std::string BASE_NAME = "base_name"; // Excludes extension.
        const std::string EXTENSION = "extension";
        const std::string LAST_MODIFIED = "last_modified";
        const std::string SIZE = "size";

        static FileTableLoader* instance;

        FileTableLoader() = default;

    public:
        static FileTableLoader* GetInstance();
        {
            if (!instance)
            {
                instance = new FileTableLoader();
            }

            return instance;
        }

        virtual ~FileTableLoader() = default;

        Table* Load(const std::string& dir);
    };
}
