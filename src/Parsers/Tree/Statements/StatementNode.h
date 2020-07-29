#ifndef __STATEMENT_NODE_H_
#define __STATEMENT_NODE_H_

#include "../BaseNode.h"

namespace FQL
{
    class StatementNode : public BaseNode
    {
    public:
        StatementNode() = default;

        virtual ~StatementNode() = default;

        virtual bool Execute() = 0;
    };
}

#endif
