// ************************************************************************* //
// * Daily Programmer 2016-02-17 Intermediate: Finding legal reversi moves * //
// * https://www.reddit.com/r/dailyprogrammer/comments/468pvf/             * //
// ************************************************************************* //

#include <fstream>
using std::ifstream;
#include <iostream>
using std::cerr;
using std::cout;
using std::endl;
#include <string>
using std::string;

#include "Board.h"

int main(int argc, const char* argv[])
{
    if (argc < 2)
    {
        cerr << "You must supply 1 or more input files" << endl;
        return 1;
    }
    for (int i = 1; i < argc; ++i)
    {
        ifstream fin(argv[i]);
        if (!fin.is_open())
        {
            cerr << "Unreadable file: " << argv[i] << endl;
            return 2;
        }
        string input[8];

        char color;
        fin >> color;           // HELP: So if I'm not mistaken, this keeps reading from the first line
        getline(fin, input[0]); //       If I don't do this first, then subsequent getlines get messed up
                                //       Is there a good way of forcing next character to the beginning
                                //       of the next line?

        for (int row = 0; row < 8; ++row) getline(fin, input[row]);
        fin.close();

        Board board(input);
        switch (color)
        {
            case 'O':
                cout << board.CountLegalWhites() << " legal moves for O" << endl;
                board.PrintLegalWhites();
                break;
            case 'X':
                cout << board.CountLegalBlacks() << " legal moves for X" << endl;
                board.PrintLegalBlacks();
                break;
        }   
    }
    return 0;
}
