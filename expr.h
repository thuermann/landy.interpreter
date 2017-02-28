//
// $Id: expr.h,v 1.10 2017/02/28 15:22:30 urs Exp $
//

#ifndef EXPR_H
#define EXPR_H

#include <iostream>

#include "symtab.h"

class expr {
public:
    virtual ~expr() {}
    virtual double eval() const = 0;
    virtual void print(std::ostream &os) const = 0;
};

class unaryop_expr : public expr {
public:
    unaryop_expr(expr *e) : e(e) {}
    virtual ~unaryop_expr() { delete e; }
    virtual double eval() const = 0;
    virtual void print(std::ostream &os) const = 0;
protected:
    expr *e;
};

class binop_expr : public expr {
public:
    binop_expr(expr *left, expr *right) : left(left), right(right) {}
    virtual ~binop_expr() { delete left; delete right; }
    virtual double eval() const = 0;
    virtual void print(std::ostream &os) const = 0;
protected:
    expr *left, *right;
};

class add_expr : public binop_expr {
public:
    add_expr(expr *left, expr *right) : binop_expr(left, right) {}
    virtual ~add_expr() {}
    virtual double eval() const;
    virtual void print(std::ostream &os) const;
};

class sub_expr : public binop_expr {
public:
    sub_expr(expr *left, expr *right) : binop_expr(left, right) {}
    virtual ~sub_expr() {}
    virtual double eval() const;
    virtual void print(std::ostream &os) const;
};

class mul_expr : public binop_expr {
public:
    mul_expr(expr *left, expr *right) : binop_expr(left, right) {}
    virtual ~mul_expr() {}
    virtual double eval() const;
    virtual void print(std::ostream &os) const;
};

class div_expr : public binop_expr {
public:
    div_expr(expr *left, expr *right) : binop_expr(left, right) {}
    virtual ~div_expr() {}
    virtual double eval() const;
    virtual void print(std::ostream &os) const;
};

class mod_expr : public binop_expr {
public:
    mod_expr(expr *left, expr *right) : binop_expr(left, right) {}
    virtual ~mod_expr() {}
    virtual double eval() const;
    virtual void print(std::ostream &os) const;
};

class neg_expr : public unaryop_expr {
public:
    neg_expr(expr *e) : unaryop_expr(e) {}
    virtual ~neg_expr() {}
    virtual double eval() const;
    virtual void print(std::ostream &os) const;
};

class eq_expr : public binop_expr {
public:
    eq_expr(expr *left, expr *right) : binop_expr(left, right) {}
    virtual ~eq_expr() {}
    virtual double eval() const;
    virtual void print(std::ostream &os) const;
};

class ne_expr : public binop_expr {
public:
    ne_expr(expr *left, expr *right) : binop_expr(left, right) {}
    virtual ~ne_expr() {}
    virtual double eval() const;
    virtual void print(std::ostream &os) const;
};

class lt_expr : public binop_expr {
public:
    lt_expr(expr *left, expr *right) : binop_expr(left, right) {}
    virtual ~lt_expr() {}
    virtual double eval() const;
    virtual void print(std::ostream &os) const;
};

class gt_expr : public binop_expr {
public:
    gt_expr(expr *left, expr *right) : binop_expr(left, right) {}
    virtual ~gt_expr() {}
    virtual double eval() const;
    virtual void print(std::ostream &os) const;
};

class le_expr : public binop_expr {
public:
    le_expr(expr *left, expr *right) : binop_expr(left, right) {}
    virtual ~le_expr() {}
    virtual double eval() const;
    virtual void print(std::ostream &os) const;
};

class ge_expr : public binop_expr {
public:
    ge_expr(expr *left, expr *right) : binop_expr(left, right) {}
    virtual ~ge_expr() {}
    virtual double eval() const;
    virtual void print(std::ostream &os) const;
};

class logand_expr : public binop_expr {
public:
    logand_expr(expr *left, expr *right) : binop_expr(left, right) {}
    virtual ~logand_expr() {}
    virtual double eval() const;
    virtual void print(std::ostream &os) const;
};

class logor_expr : public binop_expr {
public:
    logor_expr(expr *left, expr *right) : binop_expr(left, right) {}
    virtual ~logor_expr() {}
    virtual double eval() const;
    virtual void print(std::ostream &os) const;
};

class lognot_expr : public unaryop_expr {
public:
    lognot_expr(expr *e) : unaryop_expr(e) {}
    virtual ~lognot_expr() {}
    virtual double eval() const;
    virtual void print(std::ostream &os) const;
};

class cond_expr : public expr {
public:
    cond_expr(expr *cond, expr *e1, expr *e2) : cond(cond), e1(e1), e2(e2) {}
    virtual ~cond_expr() { delete cond; delete e1; delete e2; }
    virtual double eval() const;
    virtual void print(std::ostream &os) const;
protected:
    expr *cond, *e1, *e2;
};

class comma_expr : public binop_expr {
public:
    comma_expr(expr *left, expr *right) : binop_expr(left, right) {}
    virtual ~comma_expr() {}
    virtual double eval() const;
    virtual void print(std::ostream &os) const;
};

class assign_expr : public expr {
public:
    assign_expr(node *id, expr *e) : id(id), e(e) {}
    virtual ~assign_expr() { delete e; }
    virtual double eval() const;
    virtual void print(std::ostream &os) const;
protected:
    node *id;
    expr *e;
};

class assign_add_expr : public assign_expr {
public:
    assign_add_expr(node *id, expr *e) : assign_expr(id, e) {}
    virtual ~assign_add_expr() {}
    virtual double eval() const;
    virtual void print(std::ostream &os) const;
};

class assign_sub_expr : public assign_expr {
public:
    assign_sub_expr(node *id, expr *e) : assign_expr(id, e) {}
    virtual ~assign_sub_expr() {}
    virtual double eval() const;
    virtual void print(std::ostream &os) const;
};

class assign_mul_expr : public assign_expr {
public:
    assign_mul_expr(node *id, expr *e) : assign_expr(id, e) {}
    virtual ~assign_mul_expr() {}
    virtual double eval() const;
    virtual void print(std::ostream &os) const;
};

class assign_div_expr : public assign_expr {
public:
    assign_div_expr(node *id, expr *e) : assign_expr(id, e) {}
    virtual ~assign_div_expr() {}
    virtual double eval() const;
    virtual void print(std::ostream &os) const;
};

class assign_mod_expr : public assign_expr {
public:
    assign_mod_expr(node *id, expr *e) : assign_expr(id, e) {}
    virtual ~assign_mod_expr() {}
    virtual double eval() const;
    virtual void print(std::ostream &os) const;
};

class postinc_expr : public expr {
public:
    postinc_expr(node *id) : id(id) {}
    virtual ~postinc_expr() {}
    virtual double eval() const;
    virtual void print(std::ostream &os) const;
private:
    node *id;
};

class postdec_expr : public expr {
public:
    postdec_expr(node *id) : id(id) {}
    virtual ~postdec_expr() {}
    virtual double eval() const;
    virtual void print(std::ostream &os) const;
private:
    node *id;
};

class preinc_expr : public expr {
public:
    preinc_expr(node *id) : id(id) {}
    virtual ~preinc_expr() {}
    virtual double eval() const;
    virtual void print(std::ostream &os) const;
private:
    node *id;
};

class predec_expr : public expr {
public:
    predec_expr(node *id) : id(id) {}
    virtual ~predec_expr() {}
    virtual double eval() const;
    virtual void print(std::ostream &os) const;
private:
    node *id;
};

class variable_expr : public expr {
public:
    variable_expr(node *id) : id(id) {}
    virtual ~variable_expr() {}
    virtual double eval() const;
    virtual void print(std::ostream &os) const;
private:
    node *id;
};

class const_expr : public expr {
public:
    const_expr(double value) : value(value) {}
    virtual ~const_expr() {}
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
