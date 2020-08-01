#include <Parsers/Tree/Statements/SelectNode.h>

using namespace FQL;

SelectNode::SelectNode(const std::vector<SelectExpressionNode*>& expressions, int options)
{
    this->expressions = expressions;
    this->options = options;
}

SelectNode::SelectNode(DirectoryNode* dir, const std::vector<SelectExpressionNode*>& expressions, const std::vector<ClauseNode*>& clauses, int options)
    : SelectNode(expressions, options)
{
    this->dir = dir;
    this->clauses = clauses;
}

SelectNode::~SelectNode()
{
    if (this->dir != NULL)
    {
        delete this->dir;
    }

    for (auto p : this->expressions)
    {
        delete p;
    }

    for (auto p : this->clauses)
    {
        if (p != NULL)
        {
            delete p;
        }
    }
}

bool SelectNode::Execute()
{
    return true;
}

void SelectNode::DumpTree(std::ostream& out, int indent) const
{
    out << std::string(indent, ' ');
    out << "SELECT";
    out << (this->options & SELECT_DISTINCT ? " DISTINCT" : "");
    out << (this->expressions.empty() ? " *" : "");

    for (int i = 0; i < this->expressions.size(); ++i)
    {
        out << std::endl;
        this->expressions[i]->DumpTree(out, indent + 4);
        out << (i + 1 < this->expressions.size() ? "," : "");
    }

    if (this->dir != NULL)
    {
        out << std::endl;
        out << "FROM ";
        this->dir->DumpTree(out, 0);
    }

    for (auto p : this->clauses)
    {
        if (p != NULL)
        {
            out << std::endl;
            p->DumpTree(out, 0);
        }
    }
}

// =====================================================================================================

SelectExpressionNode::SelectExpressionNode(ExpressionNode* expr)
{
    // TODO: ensure not null expression.
    this->expr = expr;
}

SelectExpressionNode::SelectExpressionNode(ExpressionNode* expr, const std::string& alias)
    : SelectExpressionNode(expr)
{
    this->alias = alias;
}

SelectExpressionNode::~SelectExpressionNode()
{
    delete this->expr;
}

void SelectExpressionNode::DumpTree(std::ostream& out, int indent) const
{
    out << std::string(indent, ' ');
    this->expr->DumpTree(out, 0);
    out << (this->alias.size() > 0 ? " AS " + this->alias : "");
}
