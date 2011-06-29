/*
 * $Id: scan.l,v 1.2 2011/06/29 00:21:05 urs Exp $
 */

%{

#include <cstdlib>

#include "symtab.h"
#include "stmt.h"
#include "expr.h"
#include "parse.tab.hh"

int lineno = 1;

static symtab st;

/* Stop scanning at EOF. */
extern "C" { int yywrap(); }

%}

%x COMMENT

alpha	[_a-zA-Z]
digit	[0-9]
alnum	({alpha}|{digit})
exp	([eE][+-]?{digit}+)

ws	[ \t\f\r\b]
cbody	\/*([^*/\n]\/*|\*)*

%%

	/* keywords */

if				return IF;
else				return ELSE;
for				return FOR;
print				return PRINT;

	/* identifiers */

{alpha}{alnum}*			{
					yylval.id = st.lookup(yytext);
					return IDENTIFIER;
				}

	/* numbers.  integers are handled like floats */

{digit}+			|

{digit}*\.{digit}+{exp}?	|
{digit}+\.{exp}?		|
{digit}+{exp}			{
					yylval.value = atof(yytext);
					return NUMBER;
				}

	/* assignment operators */

"="				return '=';

	/* some other operators */

[-+*/]				return yytext[0];

"=="				return EQ;
"!="				return NE;
"<"				return '<';
">"				return '>';
"<="				return LE;
">="				return GE;

"++"				return INC;
"--"				return DEC;

	/* punctuation, parenthesis, braces, ... */

[(){};]				return yytext[0];

	/* white-space */

{ws}+				;
\n				lineno++;

	/* comments in C and C++ style */

"/*"				BEGIN(COMMENT);
<COMMENT>{cbody}\n		lineno++;
<COMMENT>{cbody}"*/"		BEGIN(0);
"//".*				;
