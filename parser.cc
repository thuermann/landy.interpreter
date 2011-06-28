//
// $Id: parser.cc,v 1.3 2011/06/28 20:41:09 urs Exp $
//

#include "parser.h"
#include "symtab.h"
#include "stmt.h"
#include "expr.h"

extern int yyparse();
extern stmt *result;

stmt *parser::parse(std::string string)
{
    return NULL;
}

stmt *parser::parse(std::istream &istream)
{
    // I still need to figure out how to best have the flex scanner
    // read its input from a std::istream or a std::string.
    //
    // For now, simply use the default and read from stdin.

    if (yyparse())
	return NULL;
    else
	return result;
}
