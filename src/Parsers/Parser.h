#pragma once

#include <string>
#include <vector>

#include "Parsers/AST.h"

extern int yyparse();

extern FILE* yyin;
extern FQL::Statements* rootNode;

namespace FQL
{
    struct Parser
    {
        static Statements Parse(std::string filepath);
    };
}
