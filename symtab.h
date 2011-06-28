//
// $Id: symtab.h,v 1.3 2011/06/28 14:21:56 urs Exp $
//

#ifndef SYMTAB_H
#define SYMTAB_H

#include <string>
#include <map>

class node {
public:
    std::string name;
    double value;

    node(std::string name) : name(name) {}
};

class symtab {
public:
    node *lookup(std::string name, bool insert = true);
    void insert(node *id);
private:
    std::map<std::string, node *> table;
};

#endif
