//
// $Id: stmt.cc,v 1.3 2011/06/28 16:27:32 urs Exp $
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
