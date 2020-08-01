#include <Parsers/Parser.h>

using namespace FQL;

std::vector<StatementNode*> Parser::Parse()
{
    yyparse();

    if (rootNode == NULL)
    {
        // TODO: throw exception.
    }

    return *rootNode;
}
