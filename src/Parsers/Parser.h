#pragma once

#include <vector>

#include <Parsers/AST.h>

extern int yyparse();

extern std::vector<FQL::StatementNode*>* rootNode;

namespace FQL
{
    struct Parser
    {
        // TODO: pass files and/or streams to parse from.
        static std::vector<StatementNode*> Parse();
    };
}
