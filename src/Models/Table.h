#ifndef __TABLE_H_
#define __TABLE_H_

#include <set>
#include <string>
#include <unordered_map>
#include <vector>

#include <Models/TableColumn.h>
#include <Models/TableRow.h>

namespace FQL
{
    class Table
    {
    private:
        std::unordered_map<std::string, TableColumn*> schema;

        std::vector<TableRow*> rows;

        std::set<std::string> updatableColumns;

    public:
        Table(const std::unordered_map<std::string, TableColumn*>& schema, std::set<std::string> updatableColumns);

        TableColumn* GetColumn(std::string key) const;

        void AddRows(const std::vector<TableRow*>& rows);
        
        void SortRows(const std::vector<std::pair<std::string, bool>>& columns);

        void LimitRows(const int limit);

        template <typename Filter>
        void FilterRows(Filter&& filter);
    };
}

#endif
