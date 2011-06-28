//
// $Id: expr.h,v 1.2 2011/06/28 14:21:36 urs Exp $
//

#ifndef EXPR_H
#define EXPR_H

#include "symtab.h"

class expr {
public:
    virtual double eval() = 0;
};

class unaryop_expr : public expr {
public:
    unaryop_expr(expr *e) : e(e) {}
    virtual double eval() = 0;
protected:
    expr *e;
};

class binop_expr : public expr {
public:
    binop_expr(expr *left, expr *right) : left(left), right(right) {}
    virtual double eval() = 0;
protected:
    expr *left, *right;
};

class add_expr : public binop_expr {
public:
    add_expr(expr *left, expr *right) : binop_expr(left, right) {}
    virtual double eval();
};

class sub_expr : public binop_expr {
public:
    sub_expr(expr *left, expr *right) : binop_expr(left, right) {}
    virtual double eval();
};

class mul_expr : public binop_expr {
public:
    mul_expr(expr *left, expr *right) : binop_expr(left, right) {}
    virtual double eval();
};

class div_expr : public binop_expr {
public:
    div_expr(expr *left, expr *right) : binop_expr(left, right) {}
    virtual double eval();
};

class neg_expr : public unaryop_expr {
public:
    neg_expr(expr *e) : unaryop_expr(e) {}
    virtual double eval();
};

class assign_expr : public expr {
public:
    assign_expr(node *id, expr *e) : id(id), e(e) {}
    virtual double eval();
private:
    node *id;
    expr *e;
};

class variable_expr : public expr {
public:
    variable_expr(node *id) : id(id) {}
    virtual double eval();
private:
    node *id;
};

class const_expr : public expr {
public:
    const_expr(double value) : value(value) {}
    virtual double eval();
private:
    double value;
};

#endif
