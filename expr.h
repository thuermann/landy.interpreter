//
// $Id: expr.h,v 1.6 2015/06/19 16:36:21 urs Exp $
//

#ifndef EXPR_H
#define EXPR_H

#include "symtab.h"

class expr {
public:
    virtual double eval() const = 0;
};

class unaryop_expr : public expr {
public:
    unaryop_expr(expr *e) : e(e) {}
    virtual double eval() const = 0;
protected:
    expr *e;
};

class binop_expr : public expr {
public:
    binop_expr(expr *left, expr *right) : left(left), right(right) {}
    virtual double eval() const = 0;
protected:
    expr *left, *right;
};

class add_expr : public binop_expr {
public:
    add_expr(expr *left, expr *right) : binop_expr(left, right) {}
    virtual double eval() const;
};

class sub_expr : public binop_expr {
public:
    sub_expr(expr *left, expr *right) : binop_expr(left, right) {}
    virtual double eval() const;
};

class mul_expr : public binop_expr {
public:
    mul_expr(expr *left, expr *right) : binop_expr(left, right) {}
    virtual double eval() const;
};

class div_expr : public binop_expr {
public:
    div_expr(expr *left, expr *right) : binop_expr(left, right) {}
    virtual double eval() const;
};

class mod_expr : public binop_expr {
public:
    mod_expr(expr *left, expr *right) : binop_expr(left, right) {}
    virtual double eval() const;
};

class neg_expr : public unaryop_expr {
public:
    neg_expr(expr *e) : unaryop_expr(e) {}
    virtual double eval() const;
};

class eq_expr : public binop_expr {
public:
    eq_expr(expr *left, expr *right) : binop_expr(left, right) {}
    virtual double eval() const;
};

class ne_expr : public binop_expr {
public:
    ne_expr(expr *left, expr *right) : binop_expr(left, right) {}
    virtual double eval() const;
};

class lt_expr : public binop_expr {
public:
    lt_expr(expr *left, expr *right) : binop_expr(left, right) {}
    virtual double eval() const;
};

class gt_expr : public binop_expr {
public:
    gt_expr(expr *left, expr *right) : binop_expr(left, right) {}
    virtual double eval() const;
};

class le_expr : public binop_expr {
public:
    le_expr(expr *left, expr *right) : binop_expr(left, right) {}
    virtual double eval() const;
};

class ge_expr : public binop_expr {
public:
    ge_expr(expr *left, expr *right) : binop_expr(left, right) {}
    virtual double eval() const;
};

class logand_expr : public binop_expr {
public:
    logand_expr(expr *left, expr *right) : binop_expr(left, right) {}
    virtual double eval() const;
};

class logor_expr : public binop_expr {
public:
    logor_expr(expr *left, expr *right) : binop_expr(left, right) {}
    virtual double eval() const;
};

class lognot_expr : public unaryop_expr {
public:
    lognot_expr(expr *e) : unaryop_expr(e) {}
    virtual double eval() const;
};

class assign_expr : public expr {
public:
    assign_expr(node *id, expr *e) : id(id), e(e) {}
    virtual double eval() const;
private:
    node *id;
    expr *e;
};

class postinc_expr : public expr {
public:
    postinc_expr(node *id) : id(id) {}
    virtual double eval() const;
private:
    node *id;
};

class postdec_expr : public expr {
public:
    postdec_expr(node *id) : id(id) {}
    virtual double eval() const;
private:
    node *id;
};

class preinc_expr : public expr {
public:
    preinc_expr(node *id) : id(id) {}
    virtual double eval() const;
private:
    node *id;
};

class predec_expr : public expr {
public:
    predec_expr(node *id) : id(id) {}
    virtual double eval() const;
private:
    node *id;
};

class variable_expr : public expr {
public:
    variable_expr(node *id) : id(id) {}
    virtual double eval() const;
private:
    node *id;
};

class const_expr : public expr {
public:
    const_expr(double value) : value(value) {}
    virtual double eval() const;
private:
    double value;
};

#endif
