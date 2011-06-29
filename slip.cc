//
// $Id: slip.cc,v 1.2 2011/06/29 01:33:52 urs Exp $
//

#include <iostream>
#include <cstdlib>

#include "parser.h"
#include "stmt.h"

int main()
{
    parser p;
    stmt *s;

    s = p.parse(std::cin);
    if (!s)
	exit(1);
    s->exec();

    return 0;
}
