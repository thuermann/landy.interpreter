//
// $Id: parser.cc,v 1.2 2011/06/28 14:21:56 urs Exp $
//

#include "parser.h"
#include "symtab.h"
#include "stmt.h"
#include "expr.h"

stmt *parser::parse(std::istream &istream)
{
    // Quick'n'dirty test of tree build & execution:
    //
    // Contruct the statement
    // for (a = 0; a - ~0; a = a * 2 + 1) print(a);

    static symtab st;
    const double maxuint = ~0U;

    expr *var = new variable_expr(st.lookup("a"));

    expr *init = new assign_expr(st.lookup("a"), new const_expr(0));
    expr *cond = new sub_expr(var, new const_expr(maxuint));

    expr *iter = new assign_expr(
	st.lookup("a"),
	new add_expr(
	    new mul_expr(
		new variable_expr(st.lookup("a")),
		new const_expr(2)
		),
	    new const_expr(1)
	    )
	);

    stmt *body = new print_stmt(var);

    stmt *s = new for_stmt(init, cond, iter, body);

    return s;
}
