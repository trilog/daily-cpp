// ********************************************************************* //
// * Daily Programmer 2016-09-14 easy: Anagram Detector                * //
// * https://www.reddit.com/r/dailyprogrammer/comments/52enht/         * //
// ********************************************************************* //

#include <algorithm>
#include <cctype>
#include <fstream>
using std::ifstream;
#include <iostream>
using std::cerr;
using std::cout;
using std::endl;
#include <string>
using std::string;

void StringSplitter(const string& input, string& first, string& second);
const string Dequoter(const string& input);
const string Scrubber(const string& input);
bool Compare(const string& first, const string& second);

int main(const int argc, const char** argv)
{
    if (argc < 2)
    {
        cerr << "Requires an input file" << endl;
        cerr << "Format: ./anadetector input.txt" << endl;
        return 1;
    }
    ifstream inFile(argv[1]);
    while (inFile.good())
    {
        string line;
        getline(inFile, line);
        if(inFile.good())
        {
            string first;
            string second;
            StringSplitter(line, first, second);
            cout << "\"" << first << "\" is";
            if (!Compare(first, second)) cout << " NOT";
            cout << " an anagram of \"" << second << "\"" << endl;
        }
    }
    if (inFile.is_open()) inFile.close();
    return 0;
}

void StringSplitter(const string& input, string& first, string& second)
{
    size_t pos = input.find('?');
    first = Dequoter(input.substr(0, pos));
    second = Dequoter(input.substr(pos));
}

const string Dequoter(const string& input)
{
    size_t pos = input.find('\"');
    return input.substr(pos + 1, input.rfind('\"') - pos - 1);
}

const string Scrubber(const string& input)
{
    string output;
    output.reserve(input.size());
    for (string::const_iterator it = input.begin(); it < input.end(); ++it)
    {
        char c = *it;
        if (isalpha(c))
        {
            if (islower(c)) c = toupper(c);
            output.push_back(c);
        }
    }
    return output;
}

bool Compare(const string& first, const string& second)
{
    string firstCopy = Scrubber(first);
    string secondCopy = Scrubber(second);
    std::sort(firstCopy.begin(), firstCopy.end());
    std::sort(secondCopy.begin(), secondCopy.end());
    return (firstCopy == secondCopy);
}
