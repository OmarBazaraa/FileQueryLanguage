#include "GroupByNode.h"

using namespace FQL;

GroupByNode::GroupByNode(std::vector<SortRuleNode *> &rules)
{
    // TODO: ensure not null empty rules.
    // TODO: ensure constant rules.
    this->rules = rules;
}

GroupByNode::~GroupByNode()
{
    for (int i = 0; i < this->rules.size(); ++i)
    {
        delete this->rules[i];
    }
}

void GroupByNode::DumpTree(std::ostream &out, int indent) const
{
    out << std::string(indent, ' ');
    out << "GROUP BY" << std::endl;
    
    for (int i = 0; i < this->rules.size(); ++i)
    {
        this->rules[i]->DumpTree(out, indent + 4);

        if (i + 1 < this->rules.size())
        {
            out << ", " << std::endl;
        }
    }
}
