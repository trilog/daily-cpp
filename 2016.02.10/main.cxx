// ************************************************************************* //
// * Daily Programmer 2016-02-10 Intermediate: Countdown (numbers game)    * //
// * https://www.reddit.com/r/dailyprogrammer/comments/452omr/             * //
// ************************************************************************* //

#include <iterator>
using std::advance;
#include <iostream>
using std::cout;
using std::endl;
#include <list>
using std::list;

#include "NumOp.h"

void Print      (const list<NumOp>& input);
void PrePermute (const list<NumOp>& numList, const list<NumOp>& opList);
void Permute    (const list<NumOp>& head,    const list<NumOp>& tail);
void OpPermute  (const list<NumOp>& opHead,  list<NumOp> opTail, const list<NumOp>& opList, const list<NumOp>& numList);

std::plus<int>       DPlus;
std::minus<int>      DMinus;
std::multiplies<int> DMultiplies;
std::divides<int>    DDivides;


int main()
{
//    list<NumOp> numList({ 25, 50, 75, 100, 3, 6 });
    list<NumOp> numList({ 25, 50 });
    list<NumOp> opList;
    opList.emplace_back(DPlus);
    opList.emplace_back(DMinus);
//    opList.emplace_back(DMultiplies);
//    opList.emplace_back(DDivides);

//    Print(numberList);
    PrePermute(numList, opList);
    return 0;
}

void Print(const list<NumOp>& input)
{
    for (const NumOp& i : input) cout << i << " ";
    cout << endl;
}

void PrePermute(const list<NumOp>& numList, const list<NumOp>& opList)
{
    list<NumOp> opHead;
    list<NumOp> opTail(numList.size() - 1, *opList.begin());
    OpPermute(opHead, opTail, opList, numList);
}

void OpPermute  (const list<NumOp>& opHead, list<NumOp> opTail, const list<NumOp>& opList, const list<NumOp>& numList)
{
    if (opTail.empty()) 
    {
        list<NumOp> newHead;
        list<NumOp> newList = numList;
        list<NumOp> newOpHead = opHead;
        newList.splice(newList.end(), newOpHead);
        Permute(newHead, newList);
        return;
    }
    opTail.pop_front();
    for (const NumOp& op : opList)
    {
        list<NumOp> newOpHead = opHead;
        newOpHead.push_back(op);
        OpPermute(newOpHead, opTail, opList, numList);
    }
}

void Permute(const list<NumOp>& head, const list<NumOp>& tail)
{
    if (tail.empty())
    {
        Print(head);
        return;
    }
    size_t size = tail.size();
    for (size_t pos = 0; pos < size; ++pos)
    {
        list<NumOp> newTail = tail;
        list<NumOp>::const_iterator it = newTail.begin();
        advance(it, pos);
        list<NumOp> newHead = head;
        newHead.emplace_back(*it);
        newTail.erase(it);
        Permute(newHead, newTail);
    }
}
