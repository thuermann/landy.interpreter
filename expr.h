//
// $Id: expr.h,v 1.9 2015/07/07 22:38:16 urs Exp $
//

#ifndef EXPR_H
#define EXPR_H

#include <iostream>

#include "symtab.h"

class expr {
public:
    virtual double eval() const = 0;
    virtual void print(std::ostream &os) const = 0;
};

class unaryop_expr : public expr {
public:
    unaryop_expr(expr *e) : e(e) {}
    virtual double eval() const = 0;
    virtual void print(std::ostream &os) const = 0;
protected:
    expr *e;
};

class binop_expr : public expr {
public:
    binop_expr(expr *left, expr *right) : left(left), right(right) {}
    virtual double eval() const = 0;
    virtual void print(std::ostream &os) const = 0;
protected:
    expr *left, *right;
};

class add_expr : public binop_expr {
public:
    add_expr(expr *left, expr *right) : binop_expr(left, right) {}
    virtual double eval() const;
    virtual void print(std::ostream &os) const;
};

class sub_expr : public binop_expr {
public:
    sub_expr(expr *left, expr *right) : binop_expr(left, right) {}
    virtual double eval() const;
    virtual void print(std::ostream &os) const;
};

class mul_expr : public binop_expr {
public:
    mul_expr(expr *left, expr *right) : binop_expr(left, right) {}
    virtual double eval() const;
    virtual void print(std::ostream &os) const;
};

class div_expr : public binop_expr {
public:
    div_expr(expr *left, expr *right) : binop_expr(left, right) {}
    virtual double eval() const;
    virtual void print(std::ostream &os) const;
};

class mod_expr : public binop_expr {
public:
    mod_expr(expr *left, expr *right) : binop_expr(left, right) {}
    virtual double eval() const;
    virtual void print(std::ostream &os) const;
};

class neg_expr : public unaryop_expr {
public:
    neg_expr(expr *e) : unaryop_expr(e) {}
    virtual double eval() const;
    virtual void print(std::ostream &os) const;
};

class eq_expr : public binop_expr {
public:
    eq_expr(expr *left, expr *right) : binop_expr(left, right) {}
    virtual double eval() const;
    virtual void print(std::ostream &os) const;
};

class ne_expr : public binop_expr {
public:
    ne_expr(expr *left, expr *right) : binop_expr(left, right) {}
    virtual double eval() const;
    virtual void print(std::ostream &os) const;
};

class lt_expr : public binop_expr {
public:
    lt_expr(expr *left, expr *right) : binop_expr(left, right) {}
    virtual double eval() const;
    virtual void print(std::ostream &os) const;
};

class gt_expr : public binop_expr {
public:
    gt_expr(expr *left, expr *right) : binop_expr(left, right) {}
    virtual double eval() const;
    virtual void print(std::ostream &os) const;
};

class le_expr : public binop_expr {
public:
    le_expr(expr *left, expr *right) : binop_expr(left, right) {}
    virtual double eval() const;
    virtual void print(std::ostream &os) const;
};

class ge_expr : public binop_expr {
public:
    ge_expr(expr *left, expr *right) : binop_expr(left, right) {}
    virtual double eval() const;
    virtual void print(std::ostream &os) const;
};

class logand_expr : public binop_expr {
public:
    logand_expr(expr *left, expr *right) : binop_expr(left, right) {}
    virtual double eval() const;
    virtual void print(std::ostream &os) const;
};

class logor_expr : public binop_expr {
public:
    logor_expr(expr *left, expr *right) : binop_expr(left, right) {}
    virtual double eval() const;
    virtual void print(std::ostream &os) const;
};

class lognot_expr : public unaryop_expr {
public:
    lognot_expr(expr *e) : unaryop_expr(e) {}
    virtual double eval() const;
    virtual void print(std::ostream &os) const;
};

class cond_expr : public expr {
public:
    cond_expr(expr *cond, expr *e1, expr *e2) : cond(cond), e1(e1), e2(e2) {}
    virtual double eval() const;
    virtual void print(std::ostream &os) const;
protected:
    expr *cond, *e1, *e2;
};

class comma_expr : public binop_expr {
public:
    comma_expr(expr *left, expr *right) : binop_expr(left, right) {}
    virtual double eval() const;
    virtual void print(std::ostream &os) const;
};

class assign_expr : public expr {
public:
    assign_expr(node *id, expr *e) : id(id), e(e) {}
    virtual double eval() const;
    virtual void print(std::ostream &os) const;
protected:
    node *id;
    expr *e;
};

class assign_add_expr : public assign_expr {
public:
    assign_add_expr(node *id, expr *e) : assign_expr(id, e) {}
    virtual double eval() const;
    virtual void print(std::ostream &os) const;
};

class assign_sub_expr : public assign_expr {
public:
    assign_sub_expr(node *id, expr *e) : assign_expr(id, e) {}
    virtual double eval() const;
    virtual void print(std::ostream &os) const;
};

class assign_mul_expr : public assign_expr {
public:
    assign_mul_expr(node *id, expr *e) : assign_expr(id, e) {}
    virtual double eval() const;
    virtual void print(std::ostream &os) const;
};

class assign_div_expr : public assign_expr {
public:
    assign_div_expr(node *id, expr *e) : assign_expr(id, e) {}
    virtual double eval() const;
    virtual void print(std::ostream &os) const;
};

class assign_mod_expr : public assign_expr {
public:
    assign_mod_expr(node *id, expr *e) : assign_expr(id, e) {}
    virtual double eval() const;
    virtual void print(std::ostream &os) const;
};

class postinc_expr : public expr {
public:
    postinc_expr(node *id) : id(id) {}
    virtual double eval() const;
    virtual void print(std::ostream &os) const;
private:
    node *id;
};

class postdec_expr : public expr {
public:
    postdec_expr(node *id) : id(id) {}
    virtual double eval() const;
    virtual void print(std::ostream &os) const;
private:
    node *id;
};

class preinc_expr : public expr {
public:
    preinc_expr(node *id) : id(id) {}
    virtual double eval() const;
    virtual void print(std::ostream &os) const;
private:
    node *id;
};

class predec_expr : public expr {
public:
    predec_expr(node *id) : id(id) {}
    virtual double eval() const;
    virtual void print(std::ostream &os) const;
private:
    node *id;
};

class variable_expr : public expr {
public:
    variable_expr(node *id) : id(id) {}
    virtual double eval() const;
    virtual void print(std::ostream &os) const;
private:
    node *id;
};

class const_expr : public expr {
public:
    const_expr(double value) : value(value) {}
    virtual double eval() const;
    virtual void print(std::ostream &os) const;
private:
    double value;
};

inline std::ostream &operator<<(std::ostream &os, const expr *e)
{
    if (e)
	e->print(os);
    else
	os << "NOP";
    return os;
}

#endif
