#pragma once

#include <vector>

#include <Parsers/Tree/BaseNode.h>
#include <Parsers/Tree/Clauses/ClauseNode.h>
#include <Parsers/Tree/Clauses/GroupByNode.h>
#include <Parsers/Tree/Clauses/HavingNode.h>
#include <Parsers/Tree/Clauses/LimitNode.h>
#include <Parsers/Tree/Clauses/OrderByNode.h>
#include <Parsers/Tree/Clauses/WhereNode.h>
#include <Parsers/Tree/DirectoryNode.h>
#include <Parsers/Tree/Expressions/ColumnNode.h>
#include <Parsers/Tree/Expressions/ExpressionNode.h>
#include <Parsers/Tree/Expressions/FunctionNode.h>
#include <Parsers/Tree/Expressions/OperatorNode.h>
#include <Parsers/Tree/Expressions/Values/BoolNode.h>
#include <Parsers/Tree/Expressions/Values/DoubleNode.h>
#include <Parsers/Tree/Expressions/Values/IntNode.h>
#include <Parsers/Tree/Expressions/Values/StringNode.h>
#include <Parsers/Tree/Expressions/Values/ValueNode.h>
#include <Parsers/Tree/SortRuleNode.h>
#include <Parsers/Tree/Statements/CreateNode.h>
#include <Parsers/Tree/Statements/DeleteNode.h>
#include <Parsers/Tree/Statements/DropNode.h>
#include <Parsers/Tree/Statements/SelectNode.h>
#include <Parsers/Tree/Statements/StatementNode.h>
#include <Parsers/Tree/Statements/UpdateNode.h>

namespace FQL
{
    typedef std::vector<BaseNode*> NodeList;
    typedef std::vector<StatementNode*> StmtList;
    typedef std::vector<ExpressionNode*> ExprList;
    typedef std::vector<SelectExpressionNode*> SelectExprList;
    typedef std::vector<UpdateAssignmentNode*> UpdateAssignList;
    typedef std::vector<SortRuleNode*> SortRuleList;
}
