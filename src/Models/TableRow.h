#pragma once

#include <map>
#include <string>

#include <Common/Enums.h>

namespace FQL
{
    class TableRow
    {
    private:
        std::map<std::string, std::string> values;

    public:
        TableRow();

        TableRow(const std::map<std::string, std::string>& values);

        std::string GetValue(const std::string& key) const;

        void UpdateValue(const std::string& key, const std::string& value);
    };
}
