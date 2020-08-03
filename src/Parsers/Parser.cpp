#include "Parsers/Parser.h"

using namespace FQL;

Statements Parser::Parse(std::string filepath)
{
    yyin = fopen(filepath.c_str(), "r");

    if (yyin == NULL)
    {
        // TODO: throw exception.
        fprintf(stderr, "error: could not open the input file '%s'!\n", filepath.c_str());
        exit(0);
    }

    yyparse();

    fclose(yyin);

    if (rootNode == NULL)
    {
        // TODO: throw exception.
        fprintf(stderr, "error: could not parse the input file '%s'!\n", filepath.c_str());
        exit(0);
    }

    return *rootNode;
}
