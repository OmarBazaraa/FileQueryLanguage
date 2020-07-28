#include "OperatorNode.h"

using namespace FileManager;

OperatorNode::OperatorNode(Operator opr) {
    this->opr = opr;
}

Operator OperatorNode::getOperation() const {
    return this->opr;
}

UnaryOperatorNode::UnaryOperatorNode(Operator opr, ExpressionNode* operand) : OperatorNode(opr) {
    // TODO: ensure not null expression.
    // TODO: add custom exceptions.

    this->operand = operand;
    this->constant = operand->isConstant();

    // TODO: ensure the data type is compatible with the operator.
    this->type = operand->getDataType();
}

UnaryOperatorNode::~UnaryOperatorNode() {
    delete this->operand;
}

void UnaryOperatorNode::dumpTree(std::ostream& out, int indent = 0) const {

}

BinaryOperatorNode::BinaryOperatorNode(Operator opr, ExpressionNode* operand1, ExpressionNode* operand2) : OperatorNode(opr) {
    // TODO: ensure not null expression.
    // TODO: add custom exceptions.

    this->operand1 = operand1;
    this->operand2 = operand2;

    this->constant = operand1->isConstant() && operand2->isConstant();

    // TODO: calculate the resulting type correctly.
    // TODO: ensure the data type is compatible with the operator.
    this->type = operand1->getDataType();
}

BinaryOperatorNode::~BinaryOperatorNode() {
    delete this->operand1;
    delete this->operand2;
}

void BinaryOperatorNode::dumpTree(std::ostream& out, int indent = 0) const {

}
