// ************************************************************************* //
// * Daily Programmer 2016-02-10 Intermediate: Countdown (numbers game)    * //
// * https://www.reddit.com/r/dailyprogrammer/comments/452omr/             * //
// ************************************************************************* //

#include <functional>
using std::plus;
using std::minus;
using std::multiplies;
using std::divides;
#include <iterator>
using std::advance;
#include <iostream>
using std::cout;
using std::endl;
#include <list>
using std::list;


void Print (const list<int>& input);
void Permute(const list<int>& input);
void Permute(const list<int>& head, const list<int>& tail);

int main()
{
    list<int> input({ 25, 50, 75, 100, 3, 6 });
    Print(input);
    Permute(input);
    
    return 0;
}

void Print(const list<int>& input)
{
    for (const int& i : input) cout << i << " ";
    cout << endl;
}

void Permute(const list<int>& input)
{
    list<int> head;
    Permute(head, input);
}

void Permute(const list<int>& head, const list<int>& tail)
{
    if (tail.empty())
    {
        Print(head);
        return;
    }
    size_t size = tail.size();
    for (size_t pos = 0; pos < size; ++pos)
    {
        list<int> newTail = tail;
        list<int>::const_iterator it = newTail.begin();
        advance(it, pos);
        list<int> newHead = head;
        newHead.emplace_back(*it);
        newTail.erase(it);
        Permute(newHead, newTail);
    }
}
