#ifndef __FILE_TABLE_ROW_H_
#define __FILE_TABLE_ROW_H_

#include <map>
#include <string>

#include "../Enums/DataTypes.h"

namespace FQL
{
    class FileTableRow
    {
    private:
        std::map<std::string, std::string> values;

    public:
        FileTableRow();

        FileTableRow(std::map<std::string, std::string> values);

        std::string GetValue(std::string key) const;

        void UpdateValue(std::string key, std::string value);
    };
}

#endif
