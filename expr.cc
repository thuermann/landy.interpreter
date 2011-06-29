//
// $Id: expr.cc,v 1.4 2011/06/29 00:24:48 urs Exp $
//

#include <cmath>

#include "expr.h"

double add_expr::eval()
{
    return left->eval() + right->eval();
}

double sub_expr::eval()
{
    return left->eval() - right->eval();
}

double mul_expr::eval()
{
    return left->eval() * right->eval();
}

double div_expr::eval()
{
    return left->eval() / right->eval();
}

double mod_expr::eval()
{
    return fmod(left->eval(), right->eval());
}

double neg_expr::eval()
{
    return -e->eval();
}

double eq_expr::eval()
{
    return left->eval() == right->eval();
}

double ne_expr::eval()
{
    return left->eval() != right->eval();
}

double lt_expr::eval()
{
    return left->eval() < right->eval();
}

double gt_expr::eval()
{
    return left->eval() > right->eval();
}

double le_expr::eval()
{
    return left->eval() <= right->eval();
}

double ge_expr::eval()
{
    return left->eval() >= right->eval();
}

double assign_expr::eval()
{
    return id->value = e->eval();
}

double postinc_expr::eval()
{
    return id->value++;
}

double postdec_expr::eval()
{
    return id->value--;
}

double preinc_expr::eval()
{
    return ++id->value;
}

double predec_expr::eval()
{
    return --id->value;
}

double variable_expr::eval()
{
    return id->value;
}

double const_expr::eval()
{
    return value;
}
