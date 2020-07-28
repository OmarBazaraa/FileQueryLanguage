#include "OperatorNode.h"

using namespace FQL;

OperatorNode::OperatorNode(Operator opr)
{
    this->opr = opr;
}

Operator OperatorNode::GetOperation() const
{
    return this->opr;
}

UnaryOperatorNode::UnaryOperatorNode(Operator opr, ExpressionNode *operand) : OperatorNode(opr)
{
    // TODO: ensure not null expression.
    // TODO: add custom exceptions.

    this->operand = operand;
    this->constant = operand->IsConstant();

    // TODO: ensure the data type is compatible with the operator.
    this->type = operand->GetDataType();
}

UnaryOperatorNode::~UnaryOperatorNode()
{
    delete this->operand;
}

void UnaryOperatorNode::DumpTree(std::ostream &out, int indent) const
{
}

BinaryOperatorNode::BinaryOperatorNode(Operator opr, ExpressionNode *operand1, ExpressionNode *operand2) : OperatorNode(opr)
{
    // TODO: ensure not null expression.
    // TODO: add custom exceptions.

    this->operand1 = operand1;
    this->operand2 = operand2;

    this->constant = operand1->IsConstant() && operand2->IsConstant();

    // TODO: calculate the resulting type correctly.
    // TODO: ensure the data type is compatible with the operator.
    this->type = operand1->GetDataType();
}

BinaryOperatorNode::~BinaryOperatorNode()
{
    delete this->operand1;
    delete this->operand2;
}

void BinaryOperatorNode::DumpTree(std::ostream &out, int indent) const
{
}
