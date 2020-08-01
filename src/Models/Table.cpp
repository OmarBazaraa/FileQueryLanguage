#include <algorithm>

#include <Models/Table.h>

using namespace FQL;

struct CompareRows
{
    const Table* table;
    const std::vector<std::pair<std::string, bool>>& columns;

    CompareRows(const Table* table, const std::vector<std::pair<std::string, bool>>& columns)
        : table(table), columns(columns)
    {
    }

    inline bool operator()(const TableRow* row1, const TableRow* row2)
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

Table::Table(const std::unordered_map<std::string, TableColumn*>& schema, std::set<std::string> updatableColumns)
    : schema(schema), updatableColumns(updatableColumns)
{
}

TableColumn* Table::GetColumn(std::string key) const
{
    return schema.at(key);
}

void Table::AddRows(const std::vector<TableRow*>& rows)
{
    for (auto r : rows)
    {
        this->rows.push_back(r);
    }
}

void Table::SortRows(const std::vector<std::pair<std::string, bool>>& columns)
{
    std::sort(this->rows.begin(), this->rows.end(), CompareRows(this, columns));
}

template <typename Filter>
void Table::FilterRows(Filter&& filter)
{
    std::vector<TableRow*>::iterator iter;

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

void Table::LimitRows(const int limit)
{
    this->rows.resize(std::min((int)this->rows.size(), limit));
}
