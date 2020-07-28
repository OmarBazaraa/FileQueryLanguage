#ifndef __AST_H_
#define __AST_H_

#include <vector>

#include "BaseNode.h"
#include "Statements/StatementNode.h"
#include "Statements/CreateDirNode.h"
#include "Statements/DropDirNode.h"
#include "Expressions/ExpressionNode.h"
#include "Expressions/ValueNode.h"
#include "Expressions/ColumnNode.h"
#include "Expressions/OperatorNode.h"
#include "Expressions/FunctionNode.h"

namespace FQL
{
    typedef std::vector<BaseNode*> NodeList;
    typedef std::vector<StatementNode*> StmtList;
    typedef std::vector<ExpressionNode*> ExprList;
}

#endif
