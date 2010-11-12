//
// $Id: symtab.h,v 1.1 2010/11/12 13:08:51 urs Exp $
//

#ifndef SYMTAB_H
#define SYMTAB_H

#include <string>
#include <map>

class node {
public:
    std::string name;
    double value;

    node(std::string name);
};

class symtab {
public:
    node *lookup(std::string name);
    void insert(node *id);
private:
    std::map<std::string, node *> table;
};

#endif
