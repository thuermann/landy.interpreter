//
// $Id: expr.cc,v 1.2 2011/06/28 14:21:36 urs Exp $
//

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

double neg_expr::eval()
{
    return -e->eval();
}

double assign_expr::eval()
{
    return id->value = e->eval();
}

double variable_expr::eval()
{
    return id->value;
}

double const_expr::eval()
{
    return value;
}
