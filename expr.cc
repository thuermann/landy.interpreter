//
// $Id: expr.cc,v 1.5 2015/06/19 15:31:30 urs Exp $
//

#include <cmath>

#include "expr.h"

double add_expr::eval() const
{
    return left->eval() + right->eval();
}

double sub_expr::eval() const
{
    return left->eval() - right->eval();
}

double mul_expr::eval() const
{
    return left->eval() * right->eval();
}

double div_expr::eval() const
{
    return left->eval() / right->eval();
}

double mod_expr::eval() const
{
    return fmod(left->eval(), right->eval());
}

double neg_expr::eval() const
{
    return -e->eval();
}

double eq_expr::eval() const
{
    return left->eval() == right->eval();
}

double ne_expr::eval() const
{
    return left->eval() != right->eval();
}

double lt_expr::eval() const
{
    return left->eval() < right->eval();
}

double gt_expr::eval() const
{
    return left->eval() > right->eval();
}

double le_expr::eval() const
{
    return left->eval() <= right->eval();
}

double ge_expr::eval() const
{
    return left->eval() >= right->eval();
}

double assign_expr::eval() const
{
    return id->value = e->eval();
}

double postinc_expr::eval() const
{
    return id->value++;
}

double postdec_expr::eval() const
{
    return id->value--;
}

double preinc_expr::eval() const
{
    return ++id->value;
}

double predec_expr::eval() const
{
    return --id->value;
}

double variable_expr::eval() const
{
    return id->value;
}

double const_expr::eval() const
{
    return value;
}
