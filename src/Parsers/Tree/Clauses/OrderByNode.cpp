#include "OrderByNode.h"

using namespace FQL;

OrderByNode::OrderByNode(std::vector<SortRuleNode *> &rules)
{
    // TODO: ensure not null empty rules.
    // TODO: ensure constant rules.
    this->rules = rules;
}

OrderByNode::~OrderByNode()
{
    for (auto p : this->rules)
    {
        delete p;
    }
}

void OrderByNode::DumpTree(std::ostream &out, int indent) const
{
    out << std::string(indent, ' ');
    out << "ORDER BY" << std::endl;
    
    for (int i = 0; i < this->rules.size(); ++i)
    {
        this->rules[i]->DumpTree(out, indent + 4);

        if (i + 1 < this->rules.size())
        {
            out << ", " << std::endl;
        }
    }
}
