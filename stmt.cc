//
// $Id: stmt.cc,v 1.1 2010/11/12 13:08:51 urs Exp $
//

#include <iostream>
#include <iomanip>

#include "stmt.h"

if_stmt::if_stmt(expr *cond, stmt *s1, stmt *s2)
    : cond(cond), s1(s1), s2(s2)
{}

void if_stmt::exec()
{
    if (cond->eval())
	s1->exec();
    else if (s2)
	s2->exec();
}

for_stmt::for_stmt(expr *init, expr *cond, expr *iter, stmt *s)
    : init(init), cond(cond), iter(iter), s(s)
{}

void for_stmt::exec()
{
    for (init->eval(); cond->eval(); iter->eval())
	s->exec();
}

print_stmt::print_stmt(expr *e)
    : e(e)
{}

void print_stmt::exec()
{
    std::cout << std::setprecision(15) << e->eval() << std::endl;
}

expr_stmt::expr_stmt(expr *e)
    : e(e)
{}

void expr_stmt::exec()
{
    e->eval();
}
