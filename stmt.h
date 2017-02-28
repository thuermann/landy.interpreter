//
// $Id: stmt.h,v 1.10 2017/02/28 15:22:30 urs Exp $
//

#ifndef STMT_H
#define STMT_H

#include <vector>

#include "expr.h"

class stmt {
public:
    static void exec(const stmt *s);

    virtual ~stmt() {}
    virtual void exec() const = 0;
    virtual void print(std::ostream &os) const = 0;
};

class stmt_list : public stmt {
public:
    virtual ~stmt_list() {
	for (auto s: slist) delete s;
    }
    void append(stmt *s);
    virtual void exec() const;
    virtual void print(std::ostream &os) const;
private:
    std::vector<stmt *> slist;
};

class if_stmt : public stmt {
public:
    if_stmt(expr *cond, stmt *s1, stmt *s2 = NULL)
	: cond(cond), s1(s1), s2(s2) {}
    virtual ~if_stmt() {
	delete cond; delete s1; delete s2;
    }
    virtual void exec() const;
    virtual void print(std::ostream &os) const;
private:
    expr *cond;
    stmt *s1, *s2;
};

class dowhile_stmt : public stmt {
public:
    dowhile_stmt(expr *cond, stmt *s) : cond(cond), s(s) {}
    virtual ~dowhile_stmt() {
	delete cond; delete s;
    }
    virtual void exec() const;
    virtual void print(std::ostream &os) const;
private:
    expr *cond;
    stmt *s;
};

class while_stmt : public stmt {
public:
    while_stmt(expr *cond, stmt *s) : cond(cond), s(s) {}
    virtual ~while_stmt() {
	delete cond; delete s;
    }
    virtual void exec() const;
    virtual void print(std::ostream &os) const;
private:
    expr *cond;
    stmt *s;
};

class for_stmt : public stmt {
public:
    for_stmt(expr *init, expr *cond, expr *iter, stmt *s)
	: init(init), cond(cond), iter(iter), s(s) {}
    virtual ~for_stmt() {
	delete init; delete cond; delete iter; delete s;
    }
    virtual void exec() const;
    virtual void print(std::ostream &os) const;
private:
    expr *init, *cond, *iter;
    stmt *s;
};

class print_stmt : public stmt {
public:
    print_stmt(expr *e) : e(e) {}
    virtual ~print_stmt() { delete e; }
    virtual void exec() const;
    virtual void print(std::ostream &os) const;
private:
    expr *e;
};

class expr_stmt : public stmt {
public:
    expr_stmt(expr *e) : e(e) {}
    virtual ~expr_stmt() { delete e; }
    virtual void exec() const;
    virtual void print(std::ostream &os) const;
private:
    expr *e;
};

inline std::ostream &operator<<(std::ostream &os, const stmt *s)
{
    if (s)
	s->print(os);
    else
	os << "NOP";
    return os;
}

#endif
