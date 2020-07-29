#include <filesystem>

#include "UpdateNode.h"
#include "../../../Common/Exceptions/BadArgumentException.h"
#include "../../../Common/Exceptions/DirectoryNotFoundException.h"
#include "../../../Common/Exceptions/FieldNotFilterableException.h"
#include "../../../Common/Exceptions/FieldNotSortableException.h"
#include "../../../Common/Exceptions/FieldNotSupportedException.h"

using namespace FileManager;

namespace fs = std::filesystem;

void ValidateParameters(const std::string &dir, int limit, const std::vector<std::pair<std::string, std::string>> &values, const std::vector<std::pair<std::string, bool>> &orderBy);

UpdateNode::UpdateNode(const char *dir, const std::vector<std::pair<std::string, std::string>> &values, const std::vector<std::pair<std::string, bool>> &orderBy, int limit)
    : UpdateNode(std::string(dir), values, orderBy, limit)
{
}

UpdateNode::UpdateNode(const std::string &dir, const std::vector<std::pair<std::string, std::string>> &values, const std::vector<std::pair<std::string, bool>> &orderBy, int limit)
    : dir(dir), values(values), orderBy(orderBy), limit(limit)
{
}

bool UpdateNode::Execute()
{
    ValidateParameters(this->dir, this->limit, this->values, this->orderBy);

    // Create simple array of FileInfo model.
    // Get files in the dir.
    // Get the fields values of the file depending on the field name.
    // Sort this array by the order by fields (custom comparator).
    // Update the specified fields.
    return true;
}

void UpdateNode::DumpTree(std::ostream &out, int indent) const
{
}

void ValidateParameters(const std::string &dir, int limit, const std::vector<std::pair<std::string, std::string>> &values, const std::vector<std::pair<std::string, bool>> &orderBy)
{
    if (!fs::exists(dir))
    {
        throw new DirectoryNotFoundException(dir);
    }

    if (limit < 0)
    {
        throw new BadArgumentException("Limit", std::to_string(limit), "The limit value cannot be less than 0");
    }
}
