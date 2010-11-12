//
// $Id: symtab.cc,v 1.1 2010/11/12 13:08:51 urs Exp $
//

#include <string>
#include <map>

#include "symtab.h"

node::node(std::string name)
    : name(name)
{}

node *symtab::lookup(std::string name)
{
    return table[name];
}

void symtab::insert(node *id)
{
    table[id->name] = id;
}
