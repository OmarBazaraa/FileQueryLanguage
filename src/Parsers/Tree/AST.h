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
#include "Statements/DeleteNode.h"
#include "Statements/DropNode.h"

#include "Clauses/ClauseNode.h"
#include "Clauses/WhereNode.h"
#include "Clauses/GroupByNode.h"
#include "Clauses/HavingNode.h"
#include "Clauses/OrderByNode.h"
#include "Clauses/LimitNode.h"

#include "Expressions/ExpressionNode.h"
#include "Expressions/FunctionNode.h"
#include "Expressions/OperatorNode.h"
#include "Expressions/ColumnNode.h"
#include "Expressions/Values/ValueNode.h"
#include "Expressions/Values/BoolNode.h"
#include "Expressions/Values/IntNode.h"
#include "Expressions/Values/DoubleNode.h"
#include "Expressions/Values/StringNode.h"

namespace FQL
{
    typedef std::vector<BaseNode *> NodeList;
    typedef std::vector<StatementNode *> StmtList;
    typedef std::vector<ExpressionNode *> ExprList;
    typedef std::vector<SelectExpressionNode *> SelectExprList;
    typedef std::vector<UpdateAssignmentNode *> UpdateAssignList;
    typedef std::vector<SortRuleNode *> SortRuleList;
}

#endif
