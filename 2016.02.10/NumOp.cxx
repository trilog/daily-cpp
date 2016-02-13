#include "NumOp.h"

using namespace std::placeholders;

// **************** Constructors **************************

NumOp::NumOp(const int& _value):
value(_value), isOperator(false), someOperator(std::modulus<int>())
{
}

NumOp::NumOp(const BinFunc& _someOperator):
value(-9999)
{
    SetOperator(_someOperator);
}

void NumOp::SetOperator(const BinFunc& _someOperator)
{
    isOperator = true;
    someOperator = std::bind(_someOperator, _1, _2);
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
        os << "fuck";
    }
    else os << numOp.GetValue();
    return os;
}
