//
// $Id: stmt.cc,v 1.8 2015/07/02 08:47:18 urs Exp $
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
    std::vector<stmt *>::const_iterator it;

    for (it = slist.begin(); it != slist.end(); ++it)
	stmt::exec(*it);
}

void stmt_list::print(std::ostream &os) const
{
    std::vector<stmt *>::const_iterator it;

    os << "{";
    for (it = slist.begin(); it != slist.end(); ++it)
	os << ' ' << *it;
    os << " }";
}

void if_stmt::exec() const
{
    if (cond->eval())
	stmt::exec(s1);
    else
	stmt::exec(s2);
}

void if_stmt::print(std::ostream &os) const
{
    os << "IF " << cond << ' ' << s1 << ' ' << s2;
}

void dowhile_stmt::exec() const
{
    do
	stmt::exec(s);
    while (cond->eval());
}

void dowhile_stmt::print(std::ostream &os) const
{
    os << "DO-WHILE " << s << ' ' << cond;
}

void while_stmt::exec() const
{
    while (cond->eval())
	stmt::exec(s);
}

void while_stmt::print(std::ostream &os) const
{
    os << "WHILE " << cond << ' ' << s;
}

void for_stmt::exec() const
{
    for (eval(init); eval(cond); eval(iter))
	stmt::exec(s);
}

void for_stmt::print(std::ostream &os) const
{
    os << "FOR " << init << ' ' << cond << ' ' << iter << ' ' << s;
}

void print_stmt::exec() const
{
    std::cout << std::setprecision(15) << e->eval() << std::endl;
}

void print_stmt::print(std::ostream &os) const
{
    os << "PRINT " << e;
}

void expr_stmt::exec() const
{
    e->eval();
}

void expr_stmt::print(std::ostream &os) const
{
    os << "EXPR " << e;
}
