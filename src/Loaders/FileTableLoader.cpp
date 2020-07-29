#include <filesystem>

#include "FileTableLoader.h"

namespace fs = std::filesystem;

using namespace FileManager;

FileTable *FileTableLoader::Load(const std::string &dir)
{
    // Create table.
    auto schema = std::map<std::string, FileTableColumn*>();

    schema[BASE_NAME] = new FileTableColumn(BASE_NAME, TYPE_STRING);
    schema[EXTENSION] = new FileTableColumn(EXTENSION, TYPE_STRING);
    schema[NAME] = new FileTableColumn(NAME, TYPE_STRING);
    schema[SIZE] = new FileTableColumn(SIZE, TYPE_INT);
    schema[LAST_MODIFIED] = new FileTableColumn(LAST_MODIFIED, TYPE_STRING);

    auto table = new FileTable(schema, {NAME});

    // Fill table rows.
    auto rows = std::vector<FileTableRow *>();

    for (const auto &entry : fs::directory_iterator(this->dir))
    {
        auto row = new FileTableRow();

        row->UpdateValue(BASE_NAME, entry.path().filename().string());
        row->UpdateValue(EXTENSION, entry.path().extension().string());
        row->UpdateValue(NAME, row->GetValue(BASE_NAME) + "." + row->GetValue(EXTENSION));
        row->UpdateValue(SIZE, std::to_string(entry.file_size()));
        row->UpdateValue(LAST_MODIFIED, std::to_string(entry.last_write_time().time_since_epoch().count())); // TODO: convert to date time.

        rows.push_back(row);
    }

    table->AddRows(rows);

    return table;
}