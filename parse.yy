/*
 * $Id: parse.yy,v 1.1 2011/06/28 20:41:09 urs Exp $
 */

%{

#include <cstdio>

#include "stmt.h"
#include "expr.h"

extern int yylex();

static void yyerror(const char *s);

stmt *result;

%}

%union {
	stmt_list *slist;
	stmt      *s;
	expr      *e;
	node      *id;
	double    value;
}

%token	IF ELSE FOR PRINT

%token	<id>	IDENTIFIER
%token	<value>	NUMBER

%type	<e>	expr opt_expr
%type	<s>	stmt
%type	<slist>	stmt_list

/* Precedence of operators from lowest to highest */
%right		'='
%left		'+' '-'
%left		'*' '/'
%right		NEG

%expect 1	/* The dangling else shift/reduce conflict */

%%

program	: stmt_list
	{
		result = $1;
	}
	;

stmt	: '{' stmt_list '}'
	{
		$$ = $2;
	}
	| IF '(' expr ')' stmt
	{
		$$ = new if_stmt($3, $5, NULL);
	}
	| IF '(' expr ')' stmt ELSE stmt
	{
		$$ = new if_stmt($3, $5, $7);
	}
	| FOR '(' opt_expr ';' opt_expr ';' opt_expr ')' stmt
	{
		$$ = new for_stmt($3, $5, $7, $9);
	}
	| PRINT '(' expr ')' ';'
	{
		$$ = new print_stmt($3);
	}
	| expr ';'
	{
		$$ = new expr_stmt($1);
	}
	;

stmt_list
	: stmt_list stmt
	{
		$$->append($2);
	}
	| /* EMPTY */
	{
		$$ = new stmt_list;
	}
	;

expr	: '(' expr ')'
	{
		$$ = $2;
	}
	| expr '+' expr
	{
		$$ = new add_expr($1, $3);
	}
	| expr '-' expr
	{
		$$ = new sub_expr($1, $3);
	}
	| expr '*' expr
	{
		$$ = new mul_expr($1, $3);
	}
	| expr '/' expr
	{
		$$ = new div_expr($1, $3);
	}
	| '-' expr %prec NEG
	{
		$$ = new neg_expr($2);
	}
	| IDENTIFIER '=' expr
	{
		$$ = new assign_expr($1, $3);
	}
	| IDENTIFIER
	{
		$$ = new variable_expr($1);
	}
	| NUMBER
	{
		$$ = new const_expr($1);
	}
	;

opt_expr
	: expr
	| /* EMPTY */
	{
		$$ = NULL;
	}
	;

%%

static void yyerror(const char *s)
{
	extern int lineno;

	fprintf(stderr, "%s in line %d\n", s, lineno);
}
