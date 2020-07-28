#include "FunctionNode.h"

using namespace FQL;

FunctionNode::FunctionNode(const std::string &name)
    : name(name)
{
    this->constant = false;
    this->type = TYPE_UNKNOWN;
}

FunctionNode::FunctionNode(const std::string &name, const std::vector<ExpressionNode*> &args)
    : name(name), args(args)
{
    // TODO: if the function is deterministic and all its arguments are constant
    // TODO: then the whole expression is constant.
    this->constant = false;
    this->type = TYPE_UNKNOWN;
}

FunctionNode::~FunctionNode()
{
    for (int i = 0; i < this->args.size(); ++i)
    {
        delete this->args[i];
    }
}

void FunctionNode::DumpTree(std::ostream &out, int indent) const
{
    out << std::string(indent, ' ');
    out << this->name;
    out << "( ";

    for (int i = 0; i < this->args.size(); ++i)
    {
        this->args[i]->DumpTree(out, 0);

        if (i + 1 < this->args.size())
        {
            out << ", ";
        }
    }
    
    out << " )";
}
