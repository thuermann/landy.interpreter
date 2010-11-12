//
// $Id: slip.cc,v 1.1 2010/11/12 13:08:51 urs Exp $
//

#include <iostream>

#include "parser.h"
#include "stmt.h"

int main()
{
    parser p;
    stmt *s;

    s = p.parse(std::cin);
    s->exec();

    return 0;
}
