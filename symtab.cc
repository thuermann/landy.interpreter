//
// $Id: symtab.cc,v 1.2 2011/06/28 14:21:36 urs Exp $
//

#include <string>
#include <map>

#include "symtab.h"

node *symtab::lookup(std::string name)
{
    return table[name];
}

void symtab::insert(node *id)
{
    table[id->name] = id;
}
