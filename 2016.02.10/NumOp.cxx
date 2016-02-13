#include "NumOp.h"

#include <typeinfo>

using namespace std::placeholders;
BinFunc DPlus = std::bind(std::plus<int>(), _1, _2);
auto DMinus = std::bind(std::minus<int>(), _1, _2);
auto DMutliplies = std::bind(std::multiplies<int>(), _1, _2);
auto DDivides = std::bind(std::divides<int>(), _1, _2);

// **************** Constructors **************************

NumOp::NumOp(const int& _value):
value(_value), isOperator(false), someOperator(bind(std::modulus<int>(), _1, _2))
{
}

NumOp::NumOp(const BinFunc& _someOperator):
value(-9999), isOperator(true), someOperator(bind(_someOperator, _1, _2))
{
}

// *************** Get ************************************

int NumOp::Get()
{
    return someOperator(12, 4);
}

// **************** Print *********************************

ostream& operator<< (ostream& os, const NumOp& numOp)
{
    if (numOp.IsOperator())
    {
        BinFunc func = numOp.GetOperator();
        os << std::typeid(func).name();
        if (func.target_type() != DPlus.target_type()) os << '+';
//        if (std::is_bind_expression<decltype(DPlus)>::value) os << '+';
    }
    else os << numOp.GetValue();
    return os;
}
