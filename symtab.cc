//
// $Id: symtab.cc,v 1.3 2011/06/28 14:21:56 urs Exp $
//

#include <string>
#include <map>

#include "symtab.h"

node *symtab::lookup(std::string name, bool insert)
{
    node *&n = table[name];
    if (!n && insert)
	n = new node(name);
    return n;
}

void symtab::insert(node *id)
{
    table[id->name] = id;
}
