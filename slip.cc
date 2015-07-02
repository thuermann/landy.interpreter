//
// $Id: slip.cc,v 1.3 2015/07/02 08:42:12 urs Exp $
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
    std::cout << s << std::endl;
    s->exec();

    return 0;
}
