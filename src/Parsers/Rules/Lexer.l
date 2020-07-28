%{
// =====================================================================================================
// Definition Section
// ==================

//
// Includes
//
#include "Parser.hpp"

//
// Function Prototypes
//

//
// Global Variables
//
%}

%{
// -------------------------------------------------------------
//
// Start States
//
%}

%s BLOCK_COMMENT

%{
// -------------------------------------------------------------
//
// Pattern Definitions (Substitutions)
//
%}

NULL                                ((?i:null))

BOOL                                ((?i:true)|(?i:false))

DIGIT                               [0-9]
INTEGER                             {DIGIT}+

FLOAT                               ({DIGIT}*\.{DIGIT}+)|({DIGIT}+\.{DIGIT}*)
EXP                                 ([eE][-+]?{INTEGER})
REAL                                ({INTEGER}{EXP}|{FLOAT}{EXP}?)

CHAR                                \'[^'\n]\'
SINGLE_QUOTED_STR                   \'([^'\n]|\'\')*\'
DOUBLE_QUOTED_STR                   \"([^"\n]|\"\")*\"
STRING                              ({SINGLE_QUOTED_STR}|{DOUBLE_QUOTED_STR})

LETTER                              [a-zA-Z_]
IDENTIFIER                          {LETTER}({LETTER}|{DIGIT})*

WHITESPACE                          [ \t\r\n]+
EOL                                 \n

%%

%{
// =====================================================================================================
// Rules Section
// =============
%}

%{
// SELECT
%}
<INITIAL>(?i:SELECT)                return SELECT;
<INITIAL>(?i:DISTINCT)              return DISTINCT;
<INITIAL>(?i:AS)                    return AS;
<INITIAL>(?i:FROM)                  return FROM;

%{
// JOIN, UNION
%}
<INITIAL>(?i:JOIN)                  return JOIN;
<INITIAL>(?i:LEFT)                  return LEFT;
<INITIAL>(?i:RIGHT)                 return RIGHT;
<INITIAL>(?i:CROSS)                 return CROSS;
<INITIAL>(?i:INNER)                 return INNER;
<INITIAL>(?i:OUTER)                 return OUTER;
<INITIAL>(?i:USING)                 return USING;
<INITIAL>(?i:ON)                    return ON;
<INITIAL>(?i:UNION)                 return UNION;

%{
// WHERE
%}
<INITIAL>(?i:WHERE)                 return WHERE;

%{
// ORDER BY
%}
<INITIAL>(?i:ORDER)                 return ORDER;
<INITIAL>(?i:BY)                    return BY;
<INITIAL>(?i:ASC)                   return ASC;
<INITIAL>(?i:DESC)                  return DESC;

%{
// GROUP BY
%}
<INITIAL>(?i:GROUP)                 return GROUP;
<INITIAL>(?i:HAVING)                return HAVING;

%{
// LIMIT
%}
<INITIAL>(?i:LIMIT)                 return LIMIT;

%{
// CREATE
%}
<INITIAL>(?i:CREATE)                return CREATE;
<INITIAL>(?i:FOLDER)                return DIRECTORY;
<INITIAL>(?i:DIRECTORY)             return DIRECTORY;
<INITIAL>(?i:DIR)                   return DIRECTORY;
<INITIAL>(?i:IF)                    return IF;
<INITIAL>(?i:EXISTS)                return EXISTS;

%{
// UPDATE
%}
<INITIAL>(?i:UPDATE)                return UPDATE;
<INITIAL>(?i:SET)                   return SET;

%{
// INSERT
%}
<INITIAL>(?i:INSERT)                return INSERT;
<INITIAL>(?i:INTO)                  return INTO;
<INITIAL>(?i:VALUES?)               return VALUES;

%{
// DELETE, DROP
%}
<INITIAL>(?i:DELETE)                return DELETE;
<INITIAL>(?i:DROP)                  return DROP;

%{
// Other Keywords
%}
<INITIAL>(?i:USE)                   return USE;
<INITIAL>(?i:OPTIMIZE)              return OPTIMIZE;
<INITIAL>(?i:WITH)                  return WITH;

%{
// Special Functions
%}
<INITIAL>(?i:IN)                    return IN;
<INITIAL>(?i:LIKE)                  return LIKE;
<INITIAL>(?i:BETWEEN)               return BETWEEN;

%{
// Operators
%}
<INITIAL>[-+*/%&|^~<>=(),.:;]       return yytext[0];
<INITIAL>"<<"                       return SHL;
<INITIAL>">>"                       return SHR;
<INITIAL>"&&"                       return AND;
<INITIAL>(?i:AND)                   return AND;
<INITIAL>"||"                       return OR;
<INITIAL>(?i:OR)                    return OR;
<INITIAL>"!"                        return NOT;
<INITIAL>(?i:NOT)                   return NOT;
<INITIAL>"IS"                       return IS;
<INITIAL>"=="                       return EQ;
<INITIAL>"!="                       return NE;
<INITIAL>"<>"                       return NE;
<INITIAL>">="                       return GE;
<INITIAL>"<="                       return LE;

%{
// Values
%}
<INITIAL>{NULL}                     return VAL_NULL;
<INITIAL>{BOOL}                     return VAL_BOOL;
<INITIAL>{INTEGER}                  return VAL_INTEGER;
<INITIAL>{REAL}                     return VAL_DOUBLE;
<INITIAL>{CHAR}                     return VAL_CHAR;
<INITIAL>{STRING}                   return VAL_STRING;
<INITIAL>{IDENTIFIER}               return VAL_IDENTIFIER;

%{
// Comments
%}
<INITIAL>"#"(.)*                    /* Ignore */ ;
<INITIAL>"--"(.)*                   /* Ignore */ ;
<INITIAL>"//"(.)*                   /* Ignore */ ;
<INITIAL>"/*"                       BEGIN BLOCK_COMMENT;
<BLOCK_COMMENT>"*/"                 BEGIN INITIAL;
<BLOCK_COMMENT>.                    /* Ignore */ ;

%{
// Others
%}
<INITIAL>{WHITESPACE}               /* Ignore */ ;
<INITIAL>.                          printf(">> Error: %s\n", yytext);

%%

// =====================================================================================================
// User Subroutines Section
// ========================

/**
 * When a lexer encounters an end of file, it optionally calls the routine `yywrap()` to find
 * out what to do next. If `yywrap()` returns 0, the scanner continues scanning, while if it
 * returns 1, the scanner returns a zero token to report the end-of-file. If your lexer does not
 * use `yywrap()` to switch files, the option `%option noyywrap` removes the calls to `yywrap()`.
 * The special token `<<EOF>>` is usually a better way to handle end-of-file situations.
 * The standard version of yywrap() in the flex library always returns 1, but if you use
 * `yywrap()`, you should replace it with one of your own. If `yywrap()` returns 0 to indicate
 * that there is more input, it needs first to adjust `yyin` to point to a new file, probably
 * using `fopen()`.
 */
int yywrap() {
    return 1;
}
