#pragma once

#include <vector>

#include <Parsers/AST.h>

extern int yyparse();

extern Statements* rootNode;

namespace FQL
{
    struct Parser
    {
        // TODO: pass files and/or streams to parse from.
        static Statements Parse();
    };
}
