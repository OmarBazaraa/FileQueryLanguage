#include <algorithm>

#include "FileTable.h"

using namespace FQL;

struct CompareRows
{
    const FileTable *table;
    const std::vector<std::pair<std::string, bool>> &columns;

    CompareRows(const FileTable* table, const std::vector<std::pair<std::string, bool>> &columns)
        : table(table), columns(columns)
    {
    }

    inline bool operator()(const FileTableRow *row1, const FileTableRow *row2)
    {
        for (auto c : this->columns)
        {
            auto columnType = table->GetColumn(c.first)->GetType();

            auto val1 = row1->GetValue(c.first);
            auto val2 = row2->GetValue(c.first);

            // TODO: cast to columns types before comparison.
            if (c.second) // ASC.
            {
                return val1 < val2;
            }
            else
            {
                return val1 > val2;
            }
        }

        return false;
    }
};

FileTable::FileTable(const std::map<std::string, FileTableColumn *> &schema, std::set<std::string> updatableColumns)
    : schema(schema), updatableColumns(updatableColumns)
{
}

FileTableColumn* FileTable::GetColumn(std::string key) const
{
    return schema.at(key);
}

void FileTable::AddRows(const std::vector<FileTableRow *> &rows)
{
    for (auto r : rows)
    {
        this->rows.push_back(r);
    }
}

void FileTable::SortRows(const std::vector<std::pair<std::string, bool>> &columns)
{
    std::sort(this->rows.begin(), this->rows.end(), CompareRows(this, columns));
}

template <typename Filter>
void FileTable::FilterRows(Filter &&filter)
{
    std::vector<FileTableRow *>::iterator iter;

    for (iter = this->rows.begin(); iter != this->rows.end();)
    {
        if (Filter(*iter))
        {
            iter = this->rows.erase(iter);
        }
        else
        {
            ++iter;
        }
    }
}

void FileTable::LimitRows(const int limit)
{
    this->rows.resize(std::min((int)this->rows.size(), limit));
}
