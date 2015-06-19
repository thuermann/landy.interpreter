//
// $Id: stmt.cc,v 1.5 2015/06/19 15:31:30 urs Exp $
//

#include <iostream>
#include <iomanip>

#include "stmt.h"

void stmt_list::append(stmt *s)
{
    slist.push_back(s);
}

void stmt_list::exec() const
{
    std::list<stmt *>::const_iterator it;

    for (it = slist.begin(); it != slist.end(); ++it)
	(*it)->exec();
}

void if_stmt::exec() const
{
    if (cond->eval())
	s1->exec();
    else if (s2)
	s2->exec();
}

void dowhile_stmt::exec() const
{
    do
	s->exec();
    while (cond->eval());
}

void while_stmt::exec() const
{
    while (cond->eval())
	s->exec();
}

void for_stmt::exec() const
{
    for (init->eval(); cond->eval(); iter->eval())
	s->exec();
}

void print_stmt::exec() const
{
    std::cout << std::setprecision(15) << e->eval() << std::endl;
}

void expr_stmt::exec() const
{
    e->eval();
}
