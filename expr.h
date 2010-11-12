//
// $Id: expr.h,v 1.1 2010/11/12 13:08:51 urs Exp $
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
    unaryop_expr(expr *e);
    virtual double eval() = 0;
protected:
    expr *e;
};

class binop_expr : public expr {
public:
    binop_expr(expr *left, expr *right);
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
    assign_expr(node *id, expr *e);
    virtual double eval();
private:
    node *id;
    expr *e;
};

class variable_expr : public expr {
public:
    variable_expr(node *id);
    virtual double eval();
private:
    node *id;
};

class const_expr : public expr {
public:
    const_expr(double value);
    virtual double eval();
private:
    double value;
};

#endif
