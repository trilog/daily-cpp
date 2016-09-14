// ********************************************************************* //
// * Daily Programmer 2016-07-11 easy: Splurthian Chemistry            * //
// * https://www.reddit.com/r/dailyprogrammer/comments/4savyr/         * //
// ********************************************************************* //

#include <cctype>
#include <fstream>
using std::ifstream;
#include <iostream>
using std::cerr;
using std::cout;
using std::endl;
#include <string>
using std::string;

const string ToUpper(const string& input);
bool Validator(const string& symbol, const string& element);
bool RecursiveValidator(string symbolU, string elementU);

int main(const int argc, const char** argv)
{
    if (argc < 2)
    {
        cerr << "Requires an input file" << endl;
        cerr << "Format: ./splurthian input.txt" << endl;
        return 1;
    }
    ifstream inFile(argv[1]);
    while (inFile.good())
    {
        string line;
        getline(inFile, line);
        if(inFile.good())
        {
            size_t delimiter = line.find(',');
            string element = line.substr(0, delimiter);
            string symbol = line.substr(delimiter + 2);
            cout << symbol << ": " << element << " -> ";
            if (Validator(symbol, element)) cout << "Valid" << endl;
            else cout << "Invalid" << endl;
        }
    }
    if (inFile.is_open()) inFile.close();
    return 0;
}

const string ToUpper(const string& input)
{
    string output;
    output.reserve(input.size());
    for (string::const_iterator it = input.begin(); it != input.end(); ++it)
    {
        char c = *it;
        if (islower(c)) c = toupper(c);
        output.push_back(c);
    }
    return output;
}

bool Validator(const string& symbol, const string& element)
{
    return RecursiveValidator(ToUpper(symbol), ToUpper(element));
}

bool RecursiveValidator(string symbolU, string elementU)
{
    if (symbolU.empty()) return true;
    size_t pos = elementU.find_first_of(*symbolU.begin());
    if (pos != string::npos) 
    {
        return RecursiveValidator(symbolU.substr(1), elementU.substr(pos + 1));
    }
    else return false;
}
