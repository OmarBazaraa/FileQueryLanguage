%{
// =====================================================================================================
// Definition Section
// ==================

//
// Includes
//

#include <cstdio>

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
    int                         valint;
    char                        valchar;
}

// -------------------------------------------------------------
//
// Token Definition
//

// SELECT
%token SELECT
%token DISTINCT
%token AS
%token FROM

// JOIN, UNION
%token JOIN
%token LEFT
%token RIGHT
%token CROSS
%token INNER
%token OUTER
%token USING
%token ON
%token UNION

// WHERE
%token WHERE

// ORDER BY
%token ORDER
%token BY
%token ASC
%token DESC

// GROUP BY
%token GROUP
%token HAVING

// LIMIT
%token LIMIT

// CREATE
%token CREATE
%token DIRECTORY
%token IF
%token EXISTS

// UPDATE
%token UPDATE
%token SET

// INSERT
%token INSERT
%token INTO
%token VALUES

// DELETE, DROP
%token DELETE
%token DROP

// Other Keywords
%token USE
%token OPTIMIZE
%token WITH

// Special Functions
%token IN
%token LIKE
%token BETWEEN

// Operators
%token SHL
%token SHR
%token AND
%token OR
%token NOT
%token IS
%token EQ
%token NE
%token GE
%token LE

// Values
%token VAL_NULL
%token VAL_BOOL
%token VAL_INTEGER
%token VAL_DOUBLE
%token VAL_CHAR
%token VAL_STRING
%token VAL_IDENTIFIER

// -------------------------------------------------------------
//
// Non-Terminal Symbol Types
//

// -------------------------------------------------------------
//
// Destructors
//

// -------------------------------------------------------------
//
// Destructors
//

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

program:                /* epsilon */               { printf(">> Empty Program <<"); }
    |                   stmt_list                   { printf(">> Complete <<"); }
    ;

stmt_list:              stmt ';'
    |                   stmt_list stmt ';'
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

select_stmt:            SELECT select_opts select_expr_list
    |                   SELECT select_opts select_expr_list
                        FROM dir_references
                        opt_where
                        opt_group_by
                        opt_having
                        opt_order_by
                        opt_limit
    ;

select_opts:            /* epsilon */
    |                   DISTINCT
    ;

select_expr_list:       '*'
    |                   select_expr
    |                   select_expr_list ',' select_expr
    ;

select_expr:            expression opt_alias
    ;

opt_alias:              /* epsilon */
    |                   identifier
    |                   AS identifier
    ;

// TODO - extend this to support joins.

dir_references:         dir_ref
    ;

dir_ref:                VAL_STRING opt_alias
    ;

opt_where:              /* epsilon */
    |                   WHERE expression
    ;

opt_group_by:           /* epsilon */
    |                   GROUP BY order_by_list
    ;

opt_having:             /* epsilon */
    |                   HAVING expression
    ;

opt_order_by:           /* epsilon */
    |                   ORDER BY order_by_list
    ;

order_by_list:          expression opt_asc_desc
    |                   order_by_list ',' expression opt_asc_desc
    ;

opt_asc_desc:           /* epsilon */
    |                   ASC
    |                   DESC
    ;

opt_limit:              /* epsilon */
    |                   LIMIT expression
    ;

// -------------------------------------------------------------
//
// CREATE Statement Rules
//

create_stmt:            create_dir_stmt
    ;

// TODO - support copying.

create_dir_stmt:        CREATE DIRECTORY opt_if_not_exists dir_ref
    ;

opt_if_not_exists:      /* epsilon */
    |                   IF NOT EXISTS
    ;

// -------------------------------------------------------------
//
// UPDATE Statement Rules
//

update_stmt:            UPDATE dir_ref
                        SET update_assign_list
                        opt_where
                        opt_order_by
                        opt_limit
    ;

update_assign_list:     column '=' expression
    |                   update_assign_list ',' column '=' expression
    ;

// -------------------------------------------------------------
//
// INSERT Statement Rules
//

// TODO - support INSERT statements.

insert_stmt:            /* epsilon */
    ;

// -------------------------------------------------------------
//
// DELETE Statement Rules
//

delete_stmt:            DELETE
                        FROM dir_ref
                        opt_where
                        opt_order_by
                        opt_limit
    ;

// -------------------------------------------------------------
//
// DROP Statement Rules
//

drop_stmt:              drop_dir_stmt
    ;

drop_dir_stmt:          DROP DIRECTORY opt_if_exists dir_ref
    ;

opt_if_exists:          /* epsilon */
    |                   IF EXISTS
    ;

// -------------------------------------------------------------
//
// Expression Rules
//

expression:             expression '+' expression               {}
    |                   expression '-' expression               {}
    |                   expression '*' expression               {}
    |                   expression '/' expression               {}
    |                   expression '%' expression               {}
    |                   '+' expression %prec U_PLUS             {}
    |                   '-' expression %prec U_MINUS            {}
    ;

expression:             expression '&' expression               {}
    |                   expression '|' expression               {}
    |                   expression '^' expression               {}
    |                   expression SHL expression               {}
    |                   expression SHR expression               {}
    |                   '~' expression                          {}
    ;

expression:             expression AND expression               {}
    |                   expression OR  expression               {}
    |                   NOT expression                          {}
    ;

// TODO - support IS operator.
// TODO - support INTERVAL expressions.

expression:             expression '>' expression               {}
    |                   expression GE  expression               {}
    |                   expression '<' expression               {}
    |                   expression LE  expression               {}
    |                   expression EQ  expression               {}
    |                   expression NE  expression               {}
    ;

expression:             '(' expression ')'                      {}
    |                   value                                   {}
    |                   column                                  {}
    |                   function_call                           {}
    ;

// ------------------------------------------------------------
//
// Function Rules
//

// TODO - support specil functions - LIKE, IN, BETWEEN.

function_call:          identifier '(' arg_list ')'             {}
    ;

arg_list:               /* epsilon */                           {}
    |                   expression                              {}
    |                   arg_list_ext ',' expression             {}
    ;

arg_list_ext:           expression                              {}
    |                   arg_list_ext ',' expression             {}
    ;

// ------------------------------------------------------------
//
// Other Rules
//

value:                  VAL_NULL                                { printf(">> Null\n"); }
    |                   VAL_BOOL                                { printf(">> Bool\n"); }
    |                   VAL_INTEGER                             { printf(">> Integer\n"); }
    |                   VAL_DOUBLE                              { printf(">> Double\n"); }
    |                   VAL_CHAR                                { printf(">> Char\n"); }
    |                   VAL_STRING                              { printf(">> String\n"); }
    ;

identifier:             VAL_IDENTIFIER                          { printf(">> Identifier\n"); }
    ;

column:                 identifier
    |                   identifier '.' identifier
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
