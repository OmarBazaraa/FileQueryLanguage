#include <Parsers/Parser.h>

using namespace FQL;

Statements Parser::Parse()
{
    yyparse();

    if (rootNode == NULL)
    {
        // TODO: throw exception.
    }

    return *rootNode;
}
