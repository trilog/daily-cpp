#ifndef __NUMOP__
#define __NUMOP__

#include <functional>
using std::function;
#include <ostream>
using std::ostream;

typedef function<int(int, int)> BinFunc;

class NumOp
{
    public:
              NumOp       (const int& _value);
              NumOp       (const BinFunc& _someOperator);
        int   Get         ();
        int   GetValue    () const { return value; }
        void  SetOperator (const BinFunc& _someOperator);
        bool  IsOperator  () const { return isOperator; }
        friend ostream& operator<< (ostream& os, const NumOp& numOp);
    private:
        int  value;
        bool isOperator;
        BinFunc someOperator;
};

#endif
