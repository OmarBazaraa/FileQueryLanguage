#ifndef __EXPRESSION_NODE_H_
#define __EXPRESSION_NODE_H_

#include <Common/Enums.h>
#include <Parsers/Tree/BaseNode.h>

namespace FQL
{
    class ExpressionNode : public BaseNode
    {
    protected:
        bool constant = false;
        DataType type = TYPE_UNKNOWN;

    public:
        ExpressionNode() = default;

        virtual ~ExpressionNode() = default;

        virtual DataType GetDataType() const;

        virtual bool IsConstant() const;

        // virtual bool GetBool() const = 0;

        // virtual int GetInt() const = 0;

        // virtual double GetDouble() const = 0;

        // virtual std::string GetString() const = 0;
    };
}

#endif
