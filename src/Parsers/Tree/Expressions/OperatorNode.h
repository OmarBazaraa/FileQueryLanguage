#ifndef __OPERATOR_NODE_H_
#define __OPERATOR_NODE_H_

#include "ExpressionNode.h"
#include "../../../Common/Enums/Operators.h"

namespace FQL
{
    class OperatorNode : public ExpressionNode
    {
    protected:
        Operator opr = OPR_UNKNOWN;

    public:
        OperatorNode(Operator opr);

        virtual ~OperatorNode() = default;

        Operator GetOperation() const;
    };

    // =====================================================================================================

    class UnaryOperatorNode : public OperatorNode
    {
    protected:
        ExpressionNode *operand = NULL;

    public:
        UnaryOperatorNode(Operator opr, ExpressionNode *operand);

        virtual ~UnaryOperatorNode();

        virtual void DumpTree(std::ostream &out, int indent = 0) const;
    };

    // =====================================================================================================

    class BinaryOperatorNode : public OperatorNode
    {
    protected:
        ExpressionNode *operand1 = NULL;
        ExpressionNode *operand2 = NULL;

    public:
        BinaryOperatorNode(Operator opr, ExpressionNode *operand1, ExpressionNode *operand2);

        virtual ~BinaryOperatorNode();

        virtual void DumpTree(std::ostream &out, int indent = 0) const;
    };
}

#endif
