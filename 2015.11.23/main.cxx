// ************************************************************************* //
// * Daily Programmer 2015-11-23 Easy: Funny Plant                         * //
// * https://www.reddit.com/r/dailyprogrammer/comments/3twuwf              * //
// ************************************************************************* //

#include <cstdlib>
#include <iostream>
using std::cin;
using std::cout;
using std::endl;
#include <vector>
using std::vector;

void Sow(vector<int>& plants, int seeds);
void Grow(vector<int>& plants, int& week);
int Harvest(vector<int>& plants);
void Print(vector<int>& plants, int week);

int main(int argc, char* argv[])
{
    int fruit = 0;
    int people = 0;
    if (argc < 2)
    {
        cout << "Number of people to support: ";
        cin >> people;
    }
    else people = atoi(argv[1]);
    if (argc < 3)
    {
        cout << "Number of starting fruit: ";
        cin >> fruit;
    }
    else fruit = atoi(argv[2]);
    cout << "To sustain " << people;
    if (people == 1) cout << " person";
    else cout << " people";
    cout << " starting with " << fruit << " fruit" << endl;

    int week = 1;
    vector<int> plants;
    Sow(plants, fruit);
    // Print(plants, week);
    Grow(plants, week);

    while (fruit <= people)
    {
        Sow(plants, fruit);
        // Print(plants, week);
        Grow(plants, week);
        fruit = Harvest(plants);
    }
    // Print(plants, week);
    cout << "Plants ready as of week " << week << endl;
    return 0;
}

void Sow(vector<int>& plants, int seeds)
{
    plants.resize(plants.size() + ((size_t) seeds), 0);
}

void Grow(vector<int>& plants, int& week)
{
    ++week;
    for (int& age : plants) ++age;
    return;
}

int Harvest(vector<int>& plants)
{
    int totalFruit = 0;
    for (int& age : plants) totalFruit += age;
    return totalFruit;
}

void Print(vector<int>& plants, int week)
{
    cout << week << ":";
    for (int& age : plants) cout << " " << age;
    cout << " - " << Harvest(plants) << endl;
    return;
}
