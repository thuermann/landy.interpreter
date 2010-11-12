//
// $Id: expr.cc,v 1.1 2010/11/12 13:08:51 urs Exp $
//

#include "expr.h"

unaryop_expr::unaryop_expr(expr *e)
    : e(e)
{}

binop_expr::binop_expr(expr *left, expr *right)
    : left(left), right(right)
{}

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

assign_expr::assign_expr(node *id, expr *e)
    : id(id), e(e)
{}

double assign_expr::eval()
{
    return id->value = e->eval();
}

variable_expr::variable_expr(node *id)
    : id(id)
{}

double variable_expr::eval()
{
    return id->value;
}

const_expr::const_expr(double value)
    : value(value)
{}

double const_expr::eval()
{
    return value;
}
