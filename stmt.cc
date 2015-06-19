//
// $Id: stmt.cc,v 1.6 2015/06/19 16:22:31 urs Exp $
//

#include <iostream>
#include <iomanip>

#include "stmt.h"

static int eval(const expr *e)
{
    return e ? e->eval() : 1;
}

void stmt::exec(const stmt *s)
{
    if (s)
	s->exec();
}

void stmt_list::append(stmt *s)
{
    slist.push_back(s);
}

void stmt_list::exec() const
{
    std::list<stmt *>::const_iterator it;

    for (it = slist.begin(); it != slist.end(); ++it)
	stmt::exec(*it);
}

void if_stmt::exec() const
{
    if (cond->eval())
	stmt::exec(s1);
    else
	stmt::exec(s2);
}

void dowhile_stmt::exec() const
{
    do
	stmt::exec(s);
    while (cond->eval());
}

void while_stmt::exec() const
{
    while (cond->eval())
	stmt::exec(s);
}

void for_stmt::exec() const
{
    for (eval(init); eval(cond); eval(iter))
	stmt::exec(s);
}

void print_stmt::exec() const
{
    std::cout << std::setprecision(15) << e->eval() << std::endl;
}

void expr_stmt::exec() const
{
    e->eval();
}
