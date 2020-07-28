#ifndef __STATEMENT_NODE_H_
#define __STATEMENT_NODE_H_

#include <string>

#include "../BaseNode.h"

namespace FileManager {

    class StatementNode : public BaseNode {
    public:

        StatementNode() = default;

        virtual ~StatementNode() = default;

        virtual bool execute() const = 0;
    };
}

#endif
