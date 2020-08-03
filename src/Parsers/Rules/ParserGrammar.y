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

#include "Common/Enums.h"
#include "Parsers/AST.h"

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
Statements* rootNode = NULL;
%}

// -------------------------------------------------------------
//
// Symbol Type Definition
//

%union
{
    FQL::StatementNode*             val_StatementNode;
    FQL::ClauseNode*                val_ClauseNode;

    FQL::ExpressionNode*            val_ExpressionNode;
    FQL::SelectExpressionNode*      val_SelectExprNode;
    FQL::UpdateAssignmentNode*      val_UpdateAssignNode;
    FQL::ValueNode*                 val_ValueNode;
    FQL::ColumnNode*                val_ColumnNode;

    FQL::Statements*                val_StmtList;
    FQL::Expressions*               val_ExprList;
    FQL::SelectExpressions*         val_SelectExprList;
    FQL::UpdateAssignments*         val_UpdateAssignList;
    FQL::SortRules*                 val_SortRuleList;

    FQL::DirectoryNode*             val_DirNode;
    FQL::SortDirection              val_SortDirection;

    bool                            val_Bool;
    int                             val_Int;
    double                          val_Double;
    char*                           val_String;
}

// -------------------------------------------------------------
//
// Token Definition
//

// Keywords
%token SELECT DISTINCT AS FROM RECURSIVE
%token UNION JOIN LEFT RIGHT CROSS INNER OUTER USING ON
%token WHERE ORDER GROUP BY ASC DESC HAVING LIMIT OFFSET
%token CREATE DIRECTORY IF EXISTS
%token UPDATE SET
%token INSERT INTO VALUES
%token DELETE DROP USE OPTIMIZE WITH
%token IN LIKE BETWEEN
%token SHL SHR AND OR NOT IS EQ NE GE LE

// Values
%token              TOKEN_NULL
%token <val_Bool>   TOKEN_BOOL
%token <val_Int>    TOKEN_INTEGER
%token <val_Double> TOKEN_DOUBLE
%token <val_String> TOKEN_STRING TOKEN_IDENTIFIER

// -------------------------------------------------------------
//
// Non-Terminal Symbol Types
//

%type <val_StatementNode>           stmt select_stmt create_stmt update_stmt insert_stmt delete_stmt drop_stmt
%type <val_ClauseNode>              opt_where opt_group_by opt_having opt_order_by opt_limit

%type <val_ExpressionNode>          expression function_call
%type <val_SelectExprNode>          select_expr
%type <val_ValueNode>               value
%type <val_ColumnNode>              column

%type <val_StmtList>                stmt_list
%type <val_ExprList>                arg_list
%type <val_SelectExprList>          select_expr_list
%type <val_UpdateAssignList>        update_assign_list

%type <val_DirNode>                 dir_ref
%type <val_SortDirection>           opt_asc_desc
%type <val_SortRuleList>            order_by_list

%type <val_Bool>                    opt_if_exists opt_if_not_exists
%type <val_Int>                     select_opts;
%type <val_String>                  opt_alias

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

program:                /* epsilon */                                   { rootNode = new Statements(); }
    |                   stmt_list                                       { rootNode = $1; }
    ;

stmt_list:              stmt ';'                                        { $$ = new Statements(); $$->push_back($1); }
    |                   stmt_list stmt ';'                              { $$ = $1; $$->push_back($2); }
    ;

stmt:                   select_stmt
    |                   create_stmt
    |                   update_stmt
    |                   insert_stmt
    |                   delete_stmt
    |                   drop_stmt
    ;

// -------------------------------------------------------------
//
// SELECT Statement Rules
//

select_stmt:            SELECT select_opts select_expr_list             { $$ = new SelectNode(*$3, $2); delete $3; }
    |                   SELECT select_opts select_expr_list
                        FROM dir_ref
                        opt_where
                        opt_group_by
                        opt_having
                        opt_order_by
                        opt_limit                                       { $$ = new SelectNode($5, *$3, { $6, $7, $8, $9, $10 }, $2); delete $3; }
    ;

select_opts:            /* epsilon */                                   { $$ = SELECT_DEFAULT; }
    |                   DISTINCT                                        { $$ = SELECT_DISTINCT; }
    ;

select_expr_list:       '*'                                             { $$ = new SelectExpressions(); }
    |                   select_expr                                     { $$ = new SelectExpressions(); $$->push_back($1); }
    |                   select_expr_list ',' select_expr                { $$ = $1; $$->push_back($3); }
    ;

select_expr:            expression                                      { $$ = new SelectExpressionNode($1); }
    |                   expression TOKEN_IDENTIFIER                     { $$ = new SelectExpressionNode($1, $2); delete $2; }
    |                   expression AS TOKEN_IDENTIFIER                  { $$ = new SelectExpressionNode($1, $3); delete $3; }
    |                   TOKEN_IDENTIFIER '=' expression                 { $$ = new SelectExpressionNode($3, $1); delete $1; }
    ;

dir_ref:                TOKEN_STRING opt_alias                          {
                                                                            if ($2 != NULL)
                                                                            {
                                                                                $$ = new DirectoryNode($1, $2);
                                                                                delete $1;
                                                                                delete $2;
                                                                            }
                                                                            else
                                                                            {
                                                                                $$ = new DirectoryNode($1);
                                                                                delete $1;
                                                                            }
                                                                        }
    |                   TOKEN_STRING RECURSIVE opt_alias                {
                                                                            if ($3 != NULL)
                                                                            {
                                                                                $$ = new DirectoryNode($1, $3, true);
                                                                                delete $1;
                                                                                delete $3;
                                                                            }
                                                                            else
                                                                            {
                                                                                $$ = new DirectoryNode($1, true);
                                                                                delete $1;
                                                                            }
                                                                        }
    ;

opt_alias:              /* epsilon */                                   { $$ = NULL; }
    |                   TOKEN_IDENTIFIER                                { $$ = $1; }
    |                   AS TOKEN_IDENTIFIER                             { $$ = $2; }
    ;

opt_where:              /* epsilon */                                   { $$ = NULL; }
    |                   WHERE expression                                { $$ = new WhereNode($2); }
    ;

opt_group_by:           /* epsilon */                                   { $$ = NULL; }
    |                   GROUP BY order_by_list                          { $$ = new GroupByNode(*$3); }
    ;

opt_having:             /* epsilon */                                   { $$ = NULL; }
    |                   HAVING expression                               { $$ = new HavingNode($2); }
    ;

opt_order_by:           /* epsilon */                                   { $$ = NULL; }
    |                   ORDER BY order_by_list                          { $$ = new OrderByNode(*$3); }
    ;

order_by_list:          expression opt_asc_desc                         { $$ = new SortRules(); $$->push_back(new SortRuleNode($1, $2)); }
    |                   order_by_list ',' expression opt_asc_desc       { $$ = $1; $$->push_back(new SortRuleNode($3, $4)); }
    ;

opt_asc_desc:           /* epsilon */                                   { $$ = SORT_ASC; }
    |                   ASC                                             { $$ = SORT_ASC; }
    |                   DESC                                            { $$ = SORT_DESC; }
    ;

opt_limit:              /* epsilon */                                   { $$ = NULL; }
    |                   LIMIT expression                                { $$ = new LimitNode($2); }
    |                   LIMIT expression OFFSET expression              { $$ = new LimitNode($2, $4); }
    ;

// -------------------------------------------------------------
//
// CREATE Statement Rules
//

// TODO - support copying.

create_stmt:            CREATE DIRECTORY opt_if_not_exists dir_ref      { $$ = new CreateNode($4, $3); }
    ;

opt_if_not_exists:      /* epsilon */                                   { $$ = false; }
    |                   IF NOT EXISTS                                   { $$ = true; }
    ;

// -------------------------------------------------------------
//
// UPDATE Statement Rules
//

update_stmt:            UPDATE dir_ref
                        SET update_assign_list
                        opt_where
                        opt_order_by
                        opt_limit                                       { $$ = new UpdateNode($2, *$4, { $5, $6, $7 }); delete $4; }
    ;

update_assign_list:     column '=' expression                           { $$ = new UpdateAssignments(); $$->push_back(new UpdateAssignmentNode($1, $3)); }
    |                   update_assign_list ',' column '=' expression    { $$ = $1; $$->push_back(new UpdateAssignmentNode($3, $5)); }
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
                        opt_limit                                       { $$ = new DeleteNode($3, { $4, $5, $6 }); }
    ;

// -------------------------------------------------------------
//
// DROP Statement Rules
//

drop_stmt:              DROP DIRECTORY opt_if_exists dir_ref            { $$ = new DropNode($4, $3); }
    ;

opt_if_exists:          /* epsilon */                                   { $$ = false; }
    |                   IF EXISTS                                       { $$ = true; }
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

arg_list:               expression                                      { $$ = new Expressions(); $$->push_back($1); }
    |                   arg_list ',' expression                         { $$ = $1; $$->push_back($3); }
    ;

// ------------------------------------------------------------
//
// Other Rules
//

value:                  TOKEN_BOOL                                      { $$ = new BoolNode($1); }
    |                   TOKEN_INTEGER                                   { $$ = new IntNode($1); }
    |                   TOKEN_DOUBLE                                    { $$ = new DoubleNode($1); }
    |                   TOKEN_STRING                                    { $$ = new StringNode($1); delete $1; }
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
