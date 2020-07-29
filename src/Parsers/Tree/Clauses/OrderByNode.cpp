#include "OrderByNode.h"

using namespace FQL;

OrderBy::OrderBy(std::vector<SortRuleNode *> &rules)
{
    // TODO: ensure not null empty rules.
    // TODO: ensure constant rules.
    this->rules = rules;
}

OrderBy::~OrderBy()
{
    for (int i = 0; i < this->rules.size(); ++i)
    {
        delete this->rules[i];
    }
}

void OrderBy::DumpTree(std::ostream &out, int indent) const
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
