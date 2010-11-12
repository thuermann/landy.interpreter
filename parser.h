//
// $Id: parser.h,v 1.1 2010/11/12 13:08:51 urs Exp $
//

#ifndef PARSER_H
#define PARSER_H

#include <string>
#include <iostream>

#include "stmt.h"

class parser {
public:
    stmt *parse(std::string program);
    stmt *parse(std::istream &istream);
};

#endif
