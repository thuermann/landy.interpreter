//
// $Id: expr.cc,v 1.8 2015/07/02 08:42:12 urs Exp $
//

#include <cmath>

#include "expr.h"

double add_expr::eval() const
{
    return left->eval() + right->eval();
}

void add_expr::print(std::ostream &os) const
{
    os << "+ " << left << ' ' << right;
}

double sub_expr::eval() const
{
    return left->eval() - right->eval();
}

void sub_expr::print(std::ostream &os) const
{
    os << "- " << left << ' ' << right;
}

double mul_expr::eval() const
{
    return left->eval() * right->eval();
}

void mul_expr::print(std::ostream &os) const
{
    os << "* " << left << ' ' << right;
}

double div_expr::eval() const
{
    return left->eval() / right->eval();
}

void div_expr::print(std::ostream &os) const
{
    os << "/ " << left << ' ' << right;
}

double mod_expr::eval() const
{
    return fmod(left->eval(), right->eval());
}

void mod_expr::print(std::ostream &os) const
{
    os << "% " << left << ' ' << right;
}

double neg_expr::eval() const
{
    return -e->eval();
}

void neg_expr::print(std::ostream &os) const
{
    os << "NEG " << e;
}

double eq_expr::eval() const
{
    return left->eval() == right->eval();
}

void eq_expr::print(std::ostream &os) const
{
    os << "== " << left << ' ' << right;
}

double ne_expr::eval() const
{
    return left->eval() != right->eval();
}

void ne_expr::print(std::ostream &os) const
{
    os << "!= " << left << ' ' << right;
}

double lt_expr::eval() const
{
    return left->eval() < right->eval();
}

void lt_expr::print(std::ostream &os) const
{
    os << "< " << left << ' ' << right;
}

double gt_expr::eval() const
{
    return left->eval() > right->eval();
}

void gt_expr::print(std::ostream &os) const
{
    os << "> " << left << ' ' << right;
}

double le_expr::eval() const
{
    return left->eval() <= right->eval();
}

void le_expr::print(std::ostream &os) const
{
    os << "<= " << left << ' ' << right;
}

double ge_expr::eval() const
{
    return left->eval() >= right->eval();
}

void ge_expr::print(std::ostream &os) const
{
    os << ">= " << left << ' ' << right;
}

double logand_expr::eval() const
{
    return left->eval() && right->eval();
}

void logand_expr::print(std::ostream &os) const
{
    os << "&& " << left << ' ' << right;
}

double logor_expr::eval() const
{
    return left->eval() || right->eval();
}

void logor_expr::print(std::ostream &os) const
{
    os << "|| " << left << ' ' << right;
}

double lognot_expr::eval() const
{
    return !e->eval();
}

void lognot_expr::print(std::ostream &os) const
{
    os << "! " << e;
}

double assign_expr::eval() const
{
    return id->value = e->eval();
}

void assign_expr::print(std::ostream &os) const
{
    os << "= " << id->name << " " << e;
}

double assign_add_expr::eval() const
{
    return id->value += e->eval();
}

void assign_add_expr::print(std::ostream &os) const
{
    os << "+= " << id->name << " " << e;
}

double assign_sub_expr::eval() const
{
    return id->value -= e->eval();
}

void assign_sub_expr::print(std::ostream &os) const
{
    os << "-= " << id->name << " " << e;
}

double assign_mul_expr::eval() const
{
    return id->value *= e->eval();
}

void assign_mul_expr::print(std::ostream &os) const
{
    os << "*= " << id->name << " " << e;
}

double assign_div_expr::eval() const
{
    return id->value /= e->eval();
}

void assign_div_expr::print(std::ostream &os) const
{
    os << "/= " << id->name << " " << e;
}

double assign_mod_expr::eval() const
{
    return id->value = fmod(id->value, e->eval());
}

void assign_mod_expr::print(std::ostream &os) const
{
    os << "%= " << id->name << " " << e;
}

double postinc_expr::eval() const
{
    return id->value++;
}

void postinc_expr::print(std::ostream &os) const
{
    os << "++ " << id->name;
}

double postdec_expr::eval() const
{
    return id->value--;
}

void postdec_expr::print(std::ostream &os) const
{
    os << "-- " << id->name;
}

double preinc_expr::eval() const
{
    return ++id->value;
}

void preinc_expr::print(std::ostream &os) const
{
    os << "++ " << id->name;
}

double predec_expr::eval() const
{
    return --id->value;
}

void predec_expr::print(std::ostream &os) const
{
    os << "-- " << id->name;
}

double variable_expr::eval() const
{
    return id->value;
}

void variable_expr::print(std::ostream &os) const
{
    os << id->name;
}

double const_expr::eval() const
{
    return value;
}

void const_expr::print(std::ostream &os) const
{
    os << value;
}
