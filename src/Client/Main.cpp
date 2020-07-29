#include <iostream>
#include <string>
#include <string.h>

#include "../Parsers/Parser.h"

using namespace std;
using namespace FQL;

//
// Compiler Definitions
//
#define LANG_NAME       "File Explorer"
#define VERSION         "0.1.0"
#define VERSION_DATE    "July 29, 2020"

//
// Functions prototypes
//
void printHelp();
void printVersion();
void parseArguments(int argc, char *argv[]);

/**
 * Main driver program.
 *
 * @param argc the number of arguments sent to the program.
 * @param argv the arguments them self as sent to the program.
 */
int main(int argc, char *argv[])
{
    auto statements = Parser::Parse();

    for (auto p : statements)
    {
        p->DumpTree(cout, 0);

        cout << endl;
        cout << "----------------------------------" << endl;
    }

    return 0;
}

/**
 * Prints the help menu of the compiler into the
 * standard output stream, then terminates the program.
 */
void printHelp()
{
    printf("%s version %s, %s\n\n", LANG_NAME, VERSION, VERSION_DATE);
    printf("Usage: %s [switches] <input_file>\n", LANG_NAME);
    printf("    -h, --help                   Print the help menu and exit.\n");
    printf("    -v, --version                Print the installed version number and exit.\n");
    printf("    -w, --warn                   Show warning messages.\n");
    exit(0);
}

/**
 * Prints the version of the compiler into the
 * standard output stream, then terminates the program.
 */
void printVersion()
{
    printf("%s version %s, %s\n\n", LANG_NAME, VERSION, VERSION_DATE);
    exit(0);
}

/**
 * Parses the passed arguments, and updates global variables in correspondence.
 *
 * @param argc the number of arguments sent to the program.
 * @param argv the arguments them self as sent to the program.
 */
void parseArguments(int argc, char *argv[])
{
    // Iterate over all sent arguments.
    while (++argv, --argc)
    {
        if (**argv == '-')
        {
            if (strcmp(*argv, "-h") == 0 || strcmp(*argv, "--help") == 0)
            {
                printHelp();
            }
            else if (strcmp(*argv, "-v") == 0 || strcmp(*argv, "--version") == 0)
            {
                printVersion();
            }
            else
            {
                fprintf(stderr, "unknown argument '%s'\n", *argv);
            }
        }
        else
        {
            fprintf(stderr, "warning: too many arguments! '%s' ignored.\n", *argv);
        }
    }
}
