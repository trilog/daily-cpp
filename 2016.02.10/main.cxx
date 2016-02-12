// ************************************************************************* //
// * Daily Programmer 2016-02-10 Intermediate: Countdown (numbers game)    * //
// * https://www.reddit.com/r/dailyprogrammer/comments/452omr/             * //
// ************************************************************************* //

#include <functional>
using std::plus;
using std::minus;
using std::multiplies;
using std::divides;
#include <iostream>
using std::cout;
using std::endl;
#include <list>
using std::list;


int       Head  (const list<int>& input);
list<int> Tail  (const list<int>& input);
void      Print (const list<int>& input);

int main()
{
    list<int> input({ 25, 50, 75, 100, 3, 6 });
    Print(input);
    
    return 0;
}

int Head(const list<int>& input)
{
    return input.front();
}

list<int> Tail(const list<int>& input)
{
    list<int> output;
    if (input.size() > 2) output.assign(++input.begin(), input.end());
    return output;
}

void Print(const list<int>& input)
{
    for (const int& i : input) cout << i << " ";
    cout << endl;
}
