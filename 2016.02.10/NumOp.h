#ifndef __NUMOP__
#define __NUMOP__

#include <ostream>
using std::ostream;
#include <list>
using std::list;

enum Operator { ACTUALLYWASNUMBERWHOLETIME, PLUS, MINUS, MULTIPLIES, DIVIDES };

class NumOp
{
    public:
              NumOp         (const int& _value);
              NumOp         (const Operator& _op);
        int   GetValue      () const { return value; }
        void  SetValue      (int _value);
        bool  IsOperator    () const { return op != ACTUALLYWASNUMBERWHOLETIME; }
        int   GetOperator   () const { return op; }
        void  SetOperator   (const Operator& _op) { op = _op; }
        friend ostream& operator<< (ostream& os, const NumOp& numOp);
    private:
        int  value;
        Operator op;
};

#endif
