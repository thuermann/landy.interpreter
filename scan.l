/*
 * $Id: scan.l,v 1.1 2011/06/28 20:41:09 urs Exp $
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
