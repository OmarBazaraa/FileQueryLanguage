#include <Parsers/Tree/Expressions/FunctionNode.h>

using namespace FQL;

FunctionNode::FunctionNode(const std::string& name)
{
    this->name = name;
}

FunctionNode::FunctionNode(const std::string& name, const std::vector<ExpressionNode*>& args)
    : FunctionNode(name)
{
    // TODO: if the function is deterministic and all its arguments are constant
    // TODO: then the whole expression is constant.
    this->args = args;
}

FunctionNode::~FunctionNode()
{
    for (auto p : this->args)
    {
        delete p;
    }
}

void FunctionNode::DumpTree(std::ostream& out, int indent) const
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
