//
// $Id: symtab.cc,v 1.5 2017/02/28 15:22:30 urs Exp $
//

#include <string>
#include <map>

#include "symtab.h"

symtab::~symtab()
{
    for (auto &pair : table)
	delete pair.second;
}

node *symtab::lookup(const std::string &name, bool insert)
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
