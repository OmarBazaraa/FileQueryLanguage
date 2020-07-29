#ifndef __DIRECTORY_REFERENCE_H_
#define __DIRECTORY_REFERENCE_H_

#include <string>

#include "BaseNode.h"

namespace FQL
{
    class DirectoryNode : public BaseNode
    {
    protected:
        bool recursive = false;
        std::string directory;
        std::string alias;

    public:
        DirectoryNode(const std::string &dir, bool recursive = false);

        DirectoryNode(const std::string &dir, const std::string &alias, bool recursive = false);

        virtual ~DirectoryNode() = default;

        virtual bool IsRecursive() const;

        virtual const std::string &GetDirectory() const;
        
        virtual const std::string &GetAlias() const;

        virtual void DumpTree(std::ostream &out, int indent = 0) const;
    };
}

#endif
