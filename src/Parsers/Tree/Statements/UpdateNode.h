#ifndef __UPDATE_NODE_H_
#define __UPDATE_NODE_H_

#include <set>
#include <string>
#include <vector>

#include "StatementNode.h"

namespace FQL
{
    class UpdateNode : public StatementNode
    {
    private:

    protected:
        const std::string &dir;

        const std::vector<std::pair<std::string, std::string>> &values;

        const std::vector<std::pair<std::string, bool>> &orderBy;
        
        int limit;

    public:
        UpdateNode(const char *dir, const std::vector<std::pair<std::string, std::string>> &values, const std::vector<std::pair<std::string, bool>> &orderBy, int limit);

        UpdateNode(const std::string &dir, const std::vector<std::pair<std::string, std::string>> &values, const std::vector<std::pair<std::string, bool>> &orderBy, int limit);

        virtual ~UpdateNode() = default;

        virtual bool Execute();

        virtual void DumpTree(std::ostream &out, int indent = 0) const;
    };
}

#endif
