%{
// =====================================================================================================
// Definition Section
// ==================

//
// Includes
//
#include <iostream>
#include <string>
#include <vector>

#include "../Tree/AST.h"
#include "../../Common/Enums/DataTypes.h"
#include "../../Common/Enums/Operators.h"

using namespace std;
using namespace FQL;

//
// Function Prototypes
//
extern int yylex();

void yyerror(const char* s);

//
// Global Variables
//
%}

// -------------------------------------------------------------
//
// Symbol Type Definition
//

%union {
    FQL::StatementNode*             val_StatementNode;

    FQL::ExpressionNode*            val_ExpressionNode;
    FQL::ExprList*                  val_ExprList;

    char*                           val_String;
}

// -------------------------------------------------------------
//
// Token Definition
//

// Keywords
%token SELECT DISTINCT AS FROM
%token UNION JOIN LEFT RIGHT CROSS INNER OUTER USING ON
%token WHERE ORDER GROUP BY ASC DESC HAVING LIMIT
%token CREATE DIRECTORY IF EXISTS
%token UPDATE SET
%token INSERT INTO VALUES
%token DELETE DROP USE OPTIMIZE WITH
%token IN LIKE BETWEEN
%token SHL SHR AND OR NOT IS EQ NE GE LE

// Values
%token <val_String> TOKEN_NULL TOKEN_BOOL TOKEN_INTEGER TOKEN_DOUBLE TOKEN_CHAR TOKEN_STRING TOKEN_IDENTIFIER

// -------------------------------------------------------------
//
// Non-Terminal Symbol Types
//

%type <val_StatementNode>           stmt create_dir_stmt drop_dir_stmt
%type <val_ExpressionNode>          expression value column function_call
%type <val_ExprList>                arg_list

// -------------------------------------------------------------
//
// Destructors
//

// TODO

// -------------------------------------------------------------
//
// Precedence & Associativity
//

// Note that order matters here.
%right      '='
%left       OR
%left       AND
%left       '|'
%left       '^'
%left       '&'
%left       EQ NE
%left       LE GE '<' '>'
%left       SHR SHL
%left       '-' '+'
%left       '*' '/' '%'
%right      NOT '~'
%right      U_PLUS U_MINUS

%%

// =====================================================================================================
// Rules Section
// =============

program:                /* epsilon */                                   { }
    |                   stmt_list                                       { }
    ;

stmt_list:              stmt ';'
    |                   stmt_list stmt ';'
    ;

stmt:                   select_stmt                                     {  }
    |                   create_stmt                                     {  }
    |                   update_stmt                                     {  }
    |                   insert_stmt                                     {  }
    |                   delete_stmt                                     {  }
    |                   drop_stmt                                       {  }
    ;
    
// Just for testing. To be removed.
stmt:                   expression                                      { $1->DumpTree(std::cout); std::cout << endl; delete $1; }
    ;

// -------------------------------------------------------------
//
// SELECT Statement Rules
//

select_stmt:            SELECT select_opts select_expr_list             {  }
    |                   SELECT select_opts select_expr_list
                        FROM dir_references
                        opt_where
                        opt_group_by
                        opt_having
                        opt_order_by
                        opt_limit                                       {  }
    ;

select_opts:            /* epsilon */                                   {  }
    |                   DISTINCT                                        {  }
    ;

select_expr_list:       '*'                                             {  }
    |                   select_expr                                     {  }
    |                   select_expr_list ',' select_expr                {  }
    ;

select_expr:            expression opt_alias                            {  }
    ;

opt_alias:              /* epsilon */                                   {  }
    |                   TOKEN_IDENTIFIER                                { delete $1; }
    |                   AS TOKEN_IDENTIFIER                             { delete $2; }
    ;

// TODO - extend this to support joins.

dir_references:         dir_ref                                         {  }
    ;

dir_ref:                TOKEN_STRING opt_alias                          { delete $1; }
    ;

opt_where:              /* epsilon */                                   {  }
    |                   WHERE expression                                {  }
    ;

opt_group_by:           /* epsilon */                                   {  }
    |                   GROUP BY order_by_list                          {  }
    ;

opt_having:             /* epsilon */                                   {  }
    |                   HAVING expression                               {  }
    ;

opt_order_by:           /* epsilon */                                   {  }
    |                   ORDER BY order_by_list                          {  }
    ;

order_by_list:          expression opt_asc_desc                         {  }
    |                   order_by_list ',' expression opt_asc_desc       {  }
    ;

opt_asc_desc:           /* epsilon */                                   {  }
    |                   ASC                                             {  }
    |                   DESC                                            {  }
    ;

opt_limit:              /* epsilon */                                   {  }
    |                   LIMIT expression                                {  }
    ;

// -------------------------------------------------------------
//
// CREATE Statement Rules
//

create_stmt:            create_dir_stmt                                 {  }
    ;

// TODO - support copying.

create_dir_stmt:        CREATE DIRECTORY opt_if_not_exists dir_ref      {  }
    ;

opt_if_not_exists:      /* epsilon */                                   {  }
    |                   IF NOT EXISTS                                   {  }
    ;

// -------------------------------------------------------------
//
// UPDATE Statement Rules
//

update_stmt:            UPDATE dir_ref
                        SET update_assign_list
                        opt_where
                        opt_order_by
                        opt_limit                                       {  }
    ;

update_assign_list:     column '=' expression                           {  }
    |                   update_assign_list ',' column '=' expression    {  }
    ;

// -------------------------------------------------------------
//
// INSERT Statement Rules
//

// TODO - support INSERT statements.

insert_stmt:            /* epsilon */                                   {  }
    ;

// -------------------------------------------------------------
//
// DELETE Statement Rules
//

delete_stmt:            DELETE
                        FROM dir_ref
                        opt_where
                        opt_order_by
                        opt_limit                                       {  }
    ;

// -------------------------------------------------------------
//
// DROP Statement Rules
//

drop_stmt:              drop_dir_stmt                                   {  }
    ;

drop_dir_stmt:          DROP DIRECTORY opt_if_exists dir_ref            {  }
    ;

opt_if_exists:          /* epsilon */                                   {  }
    |                   IF EXISTS                                       {  }
    ;

// -------------------------------------------------------------
//
// Expression Rules
//

expression:             expression '+' expression                       { $$ = new BinaryOperatorNode(OPR_ADD, $1, $3); }
    |                   expression '-' expression                       { $$ = new BinaryOperatorNode(OPR_SUB, $1, $3); }
    |                   expression '*' expression                       { $$ = new BinaryOperatorNode(OPR_MUL, $1, $3); }
    |                   expression '/' expression                       { $$ = new BinaryOperatorNode(OPR_DIV, $1, $3); }
    |                   expression '%' expression                       { $$ = new BinaryOperatorNode(OPR_MOD, $1, $3); }
    |                   '+' expression %prec U_PLUS                     { $$ = $2; }
    |                   '-' expression %prec U_MINUS                    { $$ = new UnaryOperatorNode(OPR_U_MINUS, $2); }
    ;

expression:             expression '&' expression                       { $$ = new BinaryOperatorNode(OPR_BIT_AND, $1, $3); }
    |                   expression '|' expression                       { $$ = new BinaryOperatorNode(OPR_BIT_OR, $1, $3); }
    |                   expression '^' expression                       { $$ = new BinaryOperatorNode(OPR_BIT_XOR, $1, $3); }
    |                   expression SHL expression                       { $$ = new BinaryOperatorNode(OPR_BIT_SHL, $1, $3); }
    |                   expression SHR expression                       { $$ = new BinaryOperatorNode(OPR_BIT_SHR, $1, $3); }
    |                   '~' expression                                  { $$ = new UnaryOperatorNode(OPR_BIT_NOT, $2); }
    ;

expression:             expression AND expression                       { $$ = new BinaryOperatorNode(OPR_AND, $1, $3); }
    |                   expression OR  expression                       { $$ = new BinaryOperatorNode(OPR_OR, $1, $3); }
    |                   NOT expression                                  { $$ = new UnaryOperatorNode(OPR_NOT, $2); }
    ;

// TODO - support IS operator.
// TODO - support INTERVAL expressions.

expression:             expression '>' expression                       { $$ = new BinaryOperatorNode(OPR_GREATER, $1, $3); }
    |                   expression GE  expression                       { $$ = new BinaryOperatorNode(OPR_GREATER_EQUAL, $1, $3); }
    |                   expression '<' expression                       { $$ = new BinaryOperatorNode(OPR_LESS, $1, $3); }
    |                   expression LE  expression                       { $$ = new BinaryOperatorNode(OPR_LESS_EQUAL, $1, $3); }
    |                   expression EQ  expression                       { $$ = new BinaryOperatorNode(OPR_EQUAL, $1, $3); }
    |                   expression NE  expression                       { $$ = new BinaryOperatorNode(OPR_NOT_EQUAL, $1, $3); }
    ;

expression:             '(' expression ')'                              { $$ = $2; }
    |                   value                                           { $$ = $1; }
    |                   column                                          { $$ = $1; }
    |                   function_call                                   { $$ = $1; }
    ;

// ------------------------------------------------------------
//
// Function Rules
//

// TODO - support specil functions - LIKE, IN, BETWEEN.

function_call:          TOKEN_IDENTIFIER '(' ')'                        { $$ = new FunctionNode($1); delete $1; }
    |                   TOKEN_IDENTIFIER '(' arg_list ')'               { $$ = new FunctionNode($1, *$3); delete $1; delete $3; }
    ;

arg_list:               expression                                      { $$ = new ExprList(); $$->push_back($1); }
    |                   arg_list ',' expression                         { $$ = $1; $$->push_back($3); }
    ;

// ------------------------------------------------------------
//
// Other Rules
//

value:                  TOKEN_NULL                                      { $$ = new ValueNode(TYPE_NULL, $1); delete $1; }
    |                   TOKEN_BOOL                                      { $$ = new ValueNode(TYPE_BOOL, $1); delete $1; }
    |                   TOKEN_INTEGER                                   { $$ = new ValueNode(TYPE_INT, $1); delete $1; }
    |                   TOKEN_DOUBLE                                    { $$ = new ValueNode(TYPE_DOUBLE, $1); delete $1; }
    |                   TOKEN_CHAR                                      { $$ = new ValueNode(TYPE_CHAR, $1); delete $1; }
    |                   TOKEN_STRING                                    { $$ = new ValueNode(TYPE_STRING, $1); delete $1; }
    ;

column:                 TOKEN_IDENTIFIER                                { $$ = new ColumnNode($1); delete $1; }
    |                   TOKEN_IDENTIFIER '.' TOKEN_IDENTIFIER           { $$ = new ColumnNode($1, $3); delete $1; delete $3; }
    ;

%%

// =====================================================================================================
// User Subroutines Section
// ========================

/**
 * Whenever a bison parser detects a syntax error, it calls `yyerror()` to report the error to
 * the user, passing it a single argument: a string describing the error.
 */
void yyerror(const char* s) {
    fprintf(stderr, "%s\n", s);
}
