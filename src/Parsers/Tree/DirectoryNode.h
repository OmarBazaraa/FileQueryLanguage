#pragma once

#include <string>

#include <Parsers/Tree/BaseNode.h>

namespace FQL
{
    class DirectoryNode : public BaseNode
    {
    protected:
        bool recursive = false;
        std::string path;
        std::string alias;

    public:
        DirectoryNode(const std::string& path, bool recursive = false);

        DirectoryNode(const std::string& path, const std::string& alias, bool recursive = false);

        virtual ~DirectoryNode() = default;

        virtual bool IsRecursive() const;

        virtual const std::string& GetPath() const;

        virtual const std::string& GetAlias() const;

        virtual void DumpTree(std::ostream& out, int indent = 0) const;
    };
}
