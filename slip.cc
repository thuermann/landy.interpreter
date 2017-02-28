//
// $Id: slip.cc,v 1.4 2017/02/28 15:22:30 urs Exp $
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

    delete s;

    return 0;
}
