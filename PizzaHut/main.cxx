// ****************************************************************************************** //
// * 2016.03.14 Pizza Hut Challenge A                                                       * //
// * http://blog.pizzahut.com/flavor-news/national-pi-day-math-contest-problems-are-here-2/ * //
// * Output: Answer: 3 8 1 6 5 4 7 2 9 0                                                    * //
// ****************************************************************************************** //

#include <iostream>
using std::cout;
using std::endl;
#include <algorithm>
using std::next_permutation;
#include <vector>
using std::vector;

bool Checker(const vector<int>& numVec, const int& nDigits);

int main()
{
    vector<int> numbers({ 1, 2, 3, 4, 5, 6, 7, 8, 9, 0 });
    do 
    {
        bool checksOut = true;
        for (int n = 1; n <= numbers.size(); ++n)
        {
            if (!Checker(numbers, n)) 
            {
                checksOut = false;
                break;
            }
        }
        if (checksOut) 
        {
            cout << "Answer: ";
            for (int& i : numbers) cout << i << " ";
            cout << endl;
        }
    } 
    while (next_permutation(numbers.begin(), numbers.end()));
    return 0;
}

bool Checker(const vector<int>& numVec, const int& nDigits)
{
    unsigned int newNumber = 0;
    for (int i = 0; i < nDigits; ++i)
    {
        newNumber *= 10;
        newNumber += numVec.at(i);
    }
    return (newNumber % nDigits == 0);
}
