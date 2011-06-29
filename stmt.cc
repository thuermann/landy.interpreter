//
// $Id: stmt.cc,v 1.4 2011/06/29 00:24:58 urs Exp $
//

#include <iostream>
#include <iomanip>

#include "stmt.h"

void stmt_list::append(stmt *s)
{
    slist.push_back(s);
}

void stmt_list::exec()
{
    std::list<stmt *>::const_iterator it;

    for (it = slist.begin(); it != slist.end(); ++it)
	(*it)->exec();
}

void if_stmt::exec()
{
    if (cond->eval())
	s1->exec();
    else if (s2)
	s2->exec();
}

void dowhile_stmt::exec()
{
    do
	s->exec();
    while (cond->eval());
}

void while_stmt::exec()
{
    while (cond->eval())
	s->exec();
}

void for_stmt::exec()
{
    for (init->eval(); cond->eval(); iter->eval())
	s->exec();
}

void print_stmt::exec()
{
    std::cout << std::setprecision(15) << e->eval() << std::endl;
}

void expr_stmt::exec()
{
    e->eval();
}
