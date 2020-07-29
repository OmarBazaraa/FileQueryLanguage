#ifndef __AST_H_
#define __AST_H_

#include <vector>

#include "BaseNode.h"
#include "DirectoryNode.h"
#include "SortRuleNode.h"

#include "Statements/StatementNode.h"
#include "Statements/SelectNode.h"
#include "Statements/CreateNode.h"
#include "Statements/UpdateNode.h"
#include "Statements/DropNode.h"

#include "Clauses/ClauseNode.h"
#include "Clauses/WhereNode.h"
#include "Clauses/GroupByNode.h"
#include "Clauses/HavingNode.h"
#include "Clauses/OrderByNode.h"
#include "Clauses/LimitNode.h"

#include "Expressions/ExpressionNode.h"
#include "Expressions/ValueNode.h"
#include "Expressions/ColumnNode.h"
#include "Expressions/OperatorNode.h"
#include "Expressions/FunctionNode.h"

namespace FQL
{
    typedef std::vector<BaseNode *> NodeList;
    typedef std::vector<StatementNode *> StmtList;
    typedef std::vector<ExpressionNode *> ExprList;
    typedef std::vector<SelectExpressionNode *> SelectExprList;
    typedef std::vector<SortRuleNode *> SortRuleList;
}

#endif
