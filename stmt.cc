//
// $Id: stmt.cc,v 1.2 2011/06/28 14:21:36 urs Exp $
//

#include <iostream>
#include <iomanip>

#include "stmt.h"

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
