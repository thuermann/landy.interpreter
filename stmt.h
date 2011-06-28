//
// $Id: stmt.h,v 1.2 2011/06/28 14:21:36 urs Exp $
//

#ifndef STMT_H
#define STMT_H

#include "expr.h"

class stmt {
public:
    virtual void exec() = 0;
};

class if_stmt : public stmt {
public:
    if_stmt(expr *cond, stmt *s1, stmt *s2) : cond(cond), s1(s1), s2(s2) {}
    virtual void exec();
private:
    expr *cond;
    stmt *s1, *s2;
};

class for_stmt : public stmt {
public:
    for_stmt(expr *init, expr *cond, expr *iter, stmt *s)
	: init(init), cond(cond), iter(iter), s(s) {}
    virtual void exec();
private:
    expr *init, *cond, *iter;
    stmt *s;
};

class print_stmt : public stmt {
public:
    print_stmt(expr *e) : e(e) {}
    virtual void exec();
private:
    expr *e;
};

class expr_stmt : public stmt {
public:
    expr_stmt(expr *e) : e(e) {}
    virtual void exec();
private:
    expr *e;
};

#endif
