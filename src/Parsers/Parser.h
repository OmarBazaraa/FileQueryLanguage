#ifndef __PARSER_H_
#define __PARSER_H_

#include <vector>

#include "Tree/Statements/StatementNode.h"

extern int yyparse();

extern std::vector<FQL::StatementNode *> *rootNode;

namespace FQL
{
    struct Parser
    {
        // TODO: pass files and/or streams to parse from.
        static std::vector<StatementNode *> Parse();
    };
}

#endif
