//
// $Id: symtab.h,v 1.4 2017/02/28 15:21:43 urs Exp $
//

#ifndef SYMTAB_H
#define SYMTAB_H

#include <string>
#include <map>

class node {
public:
    const std::string name;
    double value;

    node(const std::string &name) : name(name) {}
};

class symtab {
public:
    node *lookup(const std::string &name, bool insert = true);
    void insert(node *id);
private:
    std::map<const std::string, node *> table;
};

#endif
