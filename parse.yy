/*
 * $Id: parse.yy,v 1.9 2015/07/07 22:38:16 urs Exp $
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

%token	IF ELSE DO WHILE FOR PRINT

%token	<id>	IDENTIFIER
%token	<value>	NUMBER

%type	<e>	expr opt_expr
%type	<s>	stmt
%type	<slist>	stmt_list

/* Precedence of operators from lowest to highest */
%left		','
%right		'=' ASGNADD ASGNSUB ASGNMUL ASGNDIV ASGNMOD
%right		'?' ':'
%left		LOGOR
%left		LOGAND
%left		EQ NE
%left		'<' '>' LE GE
%left		'+' '-'
%left		'*' '/' '%'
%right		'!' NEG INC DEC

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
		$$ = new if_stmt($3, $5);
	}
	| IF '(' expr ')' stmt ELSE stmt
	{
		$$ = new if_stmt($3, $5, $7);
	}
	| DO stmt WHILE '(' expr ')' ';'
	{
		$$ = new dowhile_stmt($5, $2);
	}
	| WHILE '(' expr ')' stmt
	{
		$$ = new while_stmt($3, $5);
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
	| ';'
	{
		$$ = NULL;
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
	| expr '%' expr
	{
		$$ = new mod_expr($1, $3);
	}
	| '-' expr %prec NEG
	{
		$$ = new neg_expr($2);
	}
	| expr EQ expr
	{
		$$ = new eq_expr($1, $3);
	}
	| expr NE expr
	{
		$$ = new ne_expr($1, $3);
	}
	| expr '<' expr
	{
		$$ = new lt_expr($1, $3);
	}
	| expr '>' expr
	{
		$$ = new gt_expr($1, $3);
	}
	| expr LE expr
	{
		$$ = new le_expr($1, $3);
	}
	| expr GE expr
	{
		$$ = new ge_expr($1, $3);
	}
	| expr LOGAND expr
	{
		$$ = new logand_expr($1, $3);
	}
	| expr LOGOR expr
	{
		$$ = new logor_expr($1, $3);
	}
	| '!' expr
	{
		$$ = new lognot_expr($2);
	}
	| expr '?' expr ':' expr
	{
		$$ = new cond_expr($1, $3, $5);
	}
	| expr ',' expr
	{
		$$ = new comma_expr($1, $3);
	}
	| IDENTIFIER INC
	{
		$$ = new postinc_expr($1);
	}
	| IDENTIFIER DEC
	{
		$$ = new postdec_expr($1);
	}
	| INC IDENTIFIER
	{
		$$ = new preinc_expr($2);
	}
	| DEC IDENTIFIER
	{
		$$ = new predec_expr($2);
	}
	| IDENTIFIER '=' expr
	{
		$$ = new assign_expr($1, $3);
	}
	| IDENTIFIER ASGNADD expr
	{
		$$ = new assign_add_expr($1, $3);
	}
	| IDENTIFIER ASGNSUB expr
	{
		$$ = new assign_sub_expr($1, $3);
	}
	| IDENTIFIER ASGNMUL expr
	{
		$$ = new assign_mul_expr($1, $3);
	}
	| IDENTIFIER ASGNDIV expr
	{
		$$ = new assign_div_expr($1, $3);
	}
	| IDENTIFIER ASGNMOD expr
	{
		$$ = new assign_mod_expr($1, $3);
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
