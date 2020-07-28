#ifndef __OPERATOR_NODE_H_
#define __OPERATOR_NODE_H_

#include <string>

#include "ExpressionNode.h"
#include "../../Common/Enums/Operators.h"

namespace FileManager {

    class OperatorNode : public ExpressionNode {
    protected:

        Operator opr;

    public:

        OperatorNode(Operator opr);

        virtual ~OperatorNode() = default;

        Operator getOperation() const;
    };

    class UnaryOperatorNode : public OperatorNode {
    protected:

        ExpressionNode* operand;

    public:

        UnaryOperatorNode(Operator opr, ExpressionNode* operand);

        virtual ~UnaryOperatorNode() = default;

        virtual void dumpTree(std::ostream& out, int indent = 0) const;
    };

    class BinaryOperatorNode : public OperatorNode {
    protected:

        ExpressionNode* operand1;
        ExpressionNode* operand2;

    public:

        BinaryOperatorNode(Operator opr, ExpressionNode* operand1, ExpressionNode* operand2);

        virtual ~BinaryOperatorNode() = default;

        virtual void dumpTree(std::ostream& out, int indent = 0) const;
    };
}

#endif
