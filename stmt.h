//
// $Id: stmt.h,v 1.6 2015/06/19 15:31:30 urs Exp $
//

#ifndef STMT_H
#define STMT_H

#include <list>

#include "expr.h"

class stmt {
public:
    virtual void exec() const = 0;
};

class stmt_list : public stmt {
public:
    void append(stmt *s);
    virtual void exec() const;
private:
    std::list<stmt *> slist;
};

class if_stmt : public stmt {
public:
    if_stmt(expr *cond, stmt *s1, stmt *s2 = NULL)
	: cond(cond), s1(s1), s2(s2) {}
    virtual void exec() const;
private:
    expr *cond;
    stmt *s1, *s2;
};

class dowhile_stmt : public stmt {
public:
    dowhile_stmt(expr *cond, stmt *s) : cond(cond), s(s) {}
    virtual void exec() const;
private:
    expr *cond;
    stmt *s;
};

class while_stmt : public stmt {
public:
    while_stmt(expr *cond, stmt *s) : cond(cond), s(s) {}
    virtual void exec() const;
private:
    expr *cond;
    stmt *s;
};

class for_stmt : public stmt {
public:
    for_stmt(expr *init, expr *cond, expr *iter, stmt *s)
	: init(init), cond(cond), iter(iter), s(s) {}
    virtual void exec() const;
private:
    expr *init, *cond, *iter;
    stmt *s;
};

class print_stmt : public stmt {
public:
    print_stmt(expr *e) : e(e) {}
    virtual void exec() const;
private:
    expr *e;
};

class expr_stmt : public stmt {
public:
    expr_stmt(expr *e) : e(e) {}
    virtual void exec() const;
private:
    expr *e;
};

#endif
