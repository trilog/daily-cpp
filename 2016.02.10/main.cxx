// ************************************************************************* //
// * Daily Programmer 2016-02-10 Intermediate: Countdown (numbers game)    * //
// * https://www.reddit.com/r/dailyprogrammer/comments/452omr/             * //
// ************************************************************************* //

#include <cmath>
#include <iterator>
using std::advance;
#include <iostream>
using std::cout;
using std::endl;
#include <list>
using std::list;
#include <map>
using std::map;
using std::pair;
#include <stack>
using std::stack;

#include "NumOp.h"

void Print      (const list<NumOp>& input);
void Summarize  (const map<long, int>& resultMap);
void PrePermute (const list<NumOp>& numList, const list<NumOp>& opList, map<long, int>& resultMap, const int& target);
void Permute    (const list<NumOp>& head, const size_t headOps, const list<NumOp>& tail, map<long, int>& resultMap, const int& target);
void OpPermute  (const list<NumOp>& opHead, list<NumOp> opTail, const list<NumOp>& opList, const list<NumOp>& numList, map<long, int>& resultMap, const int& target);
double RPN(const list<NumOp>& input, bool& wentNegative);

int main()
{
    int target = 952;
    list<NumOp> numList({ 25, 50, 75, 100, 3, 6 });
    list<NumOp> opList({ PLUS, MINUS, MULTIPLIES, DIVIDES });
    map<long, int> resultMap;
    PrePermute(numList, opList, resultMap, target);
    // Print(resultMap);
    Summarize(resultMap);
    return 0;
}

// **************** Print *********************************

void Print(const list<NumOp>& input)
{
    for (const NumOp& i : input) cout << i << " ";
}

void Summarize(const map<long, int>& resultMap)
{
    cout << "Combinations: " << resultMap.size() << endl;
    cout << "Unobtained numbers [0, 1000]: " << endl;
    for (int i = 0; i <= 1000; ++i)
    {
        if (resultMap.find(i) == resultMap.end()) cout << i << ", ";
    }
    cout << endl;
}

// **************** Permute *******************************

void PrePermute(const list<NumOp>& numList, const list<NumOp>& opList, map<long, int>& resultMap, const int& target)
{
    list<NumOp> opHead;
    list<NumOp> opTail(numList.size() - 1, *opList.begin());
    OpPermute(opHead, opTail, opList, numList, resultMap, target);
}

void OpPermute(const list<NumOp>& opHead, list<NumOp> opTail, const list<NumOp>& opList, const list<NumOp>& numList, map<long, int>& resultMap, const int& target)
{
    if (opTail.empty()) 
    {
        list<NumOp> newHead;
        list<NumOp> newList = numList;
        list<NumOp> newOpHead = opHead;
        newList.splice(newList.end(), newOpHead);
        int headOps = 0;
        Permute(newHead, headOps, newList, resultMap, target);
        return;
    }
    opTail.pop_front();
    for (const NumOp& op : opList)
    {
        list<NumOp> newOpHead = opHead;
        newOpHead.push_back(op);
        OpPermute(newOpHead, opTail, opList, numList, resultMap, target);
    }
}

void Permute(const list<NumOp>& head, const size_t headOps, const list<NumOp>& tail, map<long, int>& resultMap, const int& target)
{
    if (head.size() == 1) // heartbeat
    {
        cout << "  ";
        Print(tail);
        cout << endl;
    }
    if (tail.empty())
    {
        bool wentNegative = false;
        double total = RPN(head, wentNegative);
        if (!wentNegative)
        {
            if (resultMap.find((long) total) != resultMap.end()) resultMap[(long) total]++;
            else resultMap[(long) total] = 1;
            if (fabs(total - (double) target) < 0.001)
            {
                cout << "Target found: ";
                Print(head);
                cout << "= " << total << endl;
            }
        }
        return;
    }
    size_t size = tail.size();
    for (size_t pos = 0; pos < size; ++pos)
    {
        size_t newHeadOps = headOps;
        list<NumOp> newHead = head;
        list<NumOp> newTail = tail;
        list<NumOp>::const_iterator it = newTail.begin();
        advance(it, pos);

        if (it->IsOperator())
        {
            if ((head.size() - (2 *newHeadOps)) < 2 ) continue;
            else ++newHeadOps;
        }

        newHead.emplace_back(*it);
        newTail.erase(it);
        Permute(newHead, newHeadOps, newTail, resultMap, target);
    }
}

// **************** Reverse Polish Notation ***************

double RPN(const list<NumOp>& input, bool& wentNegative)
{
    wentNegative = false;
    stack<double> stackRPN;
    for (const NumOp& item : input)
    {
        if (item.IsOperator())
        {
            double value2 = (double) stackRPN.top();
            stackRPN.pop();
            double value1 = (double) stackRPN.top();
            stackRPN.pop();
            switch(item.GetOperator())
            {
                case PLUS:
                    stackRPN.emplace(value1 + value2);
                    break;
                case MINUS:
                    stackRPN.emplace(value1 - value2);
                    break;
                case MULTIPLIES:
                    stackRPN.emplace(value1 * value2);
                    break;
                case DIVIDES:
                    stackRPN.emplace(value1 / value2);
                    break;
            }
            if (stackRPN.top() < 0) wentNegative = true;
        }
        else stackRPN.emplace((double) item.GetValue());
    }
    return stackRPN.top();
}
