#include "NumOp.h"

// **************** Constructors **************************

NumOp::NumOp(const int& _value):
value(_value), op(ACTUALLYWASNUMBERWHOLETIME)
{
}

NumOp::NumOp(const Operator& _op):
value(-9999), op(_op)
{
}

// *************** SetValue *******************************

void NumOp::SetValue(int _value)
{
    op = ACTUALLYWASNUMBERWHOLETIME;
    value = _value;
}

// **************** Print *********************************

ostream& operator<< (ostream& os, const NumOp& numOp)
{
    switch(numOp.GetOperator())
    {
        case PLUS:
            os << '+';
            break;
        case MINUS:
            os << '-';
            break;
        case MULTIPLIES:
            os << '*';
            break;
        case DIVIDES:
            os << '/';
            break;
        default:
            os << numOp.GetValue();
    }
    return os;
}
