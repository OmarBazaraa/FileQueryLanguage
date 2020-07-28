#ifndef __EXPRESSION_NODE_H_
#define __EXPRESSION_NODE_H_

#include "../BaseNode.h"
#include "../../../Common/Enums/DataTypes.h"

namespace FileManager {

    class ExpressionNode : public BaseNode {
    protected:

        /**
         * Flag that indicates whether the expression is constant or variable.
         */
        bool constant = false;

        /**
         * The data type of the expression.
         */
        DataType type = TYPE_UNKNOWN;

    public:

        ExpressionNode() = default;

        virtual ~ExpressionNode() = default;

        virtual bool isConstant() const;
        
        virtual DataType getDataType() const;
    };
}

#endif
