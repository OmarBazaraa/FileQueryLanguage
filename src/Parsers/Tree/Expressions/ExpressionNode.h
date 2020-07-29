#ifndef __EXPRESSION_NODE_H_
#define __EXPRESSION_NODE_H_

#include "../BaseNode.h"
#include "../../../Common/Enums/DataTypes.h"

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

        virtual bool IsConstant() const;

        virtual DataType GetDataType() const;
    };
}

#endif
