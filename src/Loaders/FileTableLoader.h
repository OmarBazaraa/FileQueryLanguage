#ifndef __FILE_TABLE_LOADER_H_
#define __FILE_TABLE_LOADER_H_

#include "Loader.h"
#include "../Common/Models/FileTable.h"

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

        static FileTableLoader *instance;

        FileTableLoader() {}

    public:
        static FileTableLoader *GetInstance();
        {
            if (!instance)
            {
                instance = new FileTableLoader;
            }

            return instance;
        }

        FileTableLoader();

        virtual ~FileTableLoader() = default;

        FileTable *Load(const std::string &dir);
    };
}

#endif
