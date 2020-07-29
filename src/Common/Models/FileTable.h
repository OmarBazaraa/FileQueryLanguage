#ifndef __FILE_TABLE_H_
#define __FILE_TABLE_H_

#include <map>
#include <set>
#include <string>
#include <vector>

#include "FileTableColumn.h"
#include "FileTableRow.h"

namespace FileManager
{
    class FileTable
    {
    private:
        std::map<std::string, FileTableColumn *> schema;

        std::vector<FileTableRow *> rows;

        std::set<std::string> updatableColumns;

    public:
        FileTable(const std::map<std::string, FileTableColumn *> &schema, std::set<std::string> updatableColumns);
        
        FileTableColumn *GetColumn(std::string key) const;
        
        void AddRows(const std::vector<FileTableRow *> &rows);
        void SortRows(const std::vector<std::pair<std::string, bool>> &columns);
        void LimitRows(const int limit);

        template <typename Filter>
        void FilterRows(Filter &&filter);
    };
}

#endif
