#ifndef __CREATE_NODE_H_
#define __CREATE_NODE_H_

#include <string>

#include "StatementNode.h"

namespace FileManager
{
    class CreateNode : public StatementNode
    {
    protected:
        // TODO: change to custom type.
        const std::string dir;

        const bool createIfNotExists = false;

    public:
        CreateNode(const char *dir, bool createIfNotExists = false);

        CreateNode(const std::string &dir, bool createIfNotExists = false);

        virtual ~CreateNode() = default;

        virtual bool Execute();

        virtual void DumpTree(std::ostream &out, int indent = 0) const;
    };
}

#endif
