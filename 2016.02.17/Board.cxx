#include <iostream>
using std::cout;
using std::endl;
#include <string>
using std::string;

#include "Board.h"

// **************** Con/Destructors ***********************

Board::Board(const string* input)
{
    for (size_t i = 0; i < 8; ++i)
    {
        for (size_t j = 0; j < 8; ++j)
        {
            switch (input[i][j])
            {
                case '-':
                    board[i][j] = EMPTY;
                    break;
                case 'X':
                    board[i][j] = BLACK;
                    break;
                case 'O':
                    board[i][j] = WHITE;
                    break;
                case '0': // Just in case
                    board[i][j] = WHITE;
                    break;
                default:
                    board[i][j] = EMPTY;
                    break;
            }
        }
    }
    Analyze();
}

// **************** Print *********************************

void Board::Print() const
{
    char legalChar[3] = { '-', '-', '-' };
    Print(legalChar);
}

void Board::PrintLegalBlacks() const
{
    char legalChar[3] = { '*', '-', '*' };
    Print(legalChar);
}

void Board::PrintLegalWhites() const
{
    char legalChar[3] = { '-', '*', '*' };
    Print(legalChar);
}

void Board::Print(const char* legalChar) const
{
    for (size_t i = 0; i < 8; ++i)
    {
        for (size_t j = 0; j < 8; ++j)
        {
            switch (board[i][j])
            {
                case EMPTY:
                    cout << '-';
                    break;
                case BLACK:
                    cout << 'X';
                    break;
                case WHITE:
                    cout << 'O';
                    break;
                case LEGALBLACK:
                    cout << legalChar[0];
                    break;
                case LEGALWHITE:
                    cout << legalChar[1];
                    break;
                case LEGALBOTH:
                    cout << legalChar[2];
                    break;
            }
        }
        cout << endl;
    }
}

// **************** Analyze *******************************

void Board::Analyze()
{
    for (int i = 0; i < 8; ++i)
    {
        for (int j = 0; j < 8; ++j)
        {
            if ((board[i][j] != BLACK) && (board[i][j] != WHITE))
            {
                bool legalBlacks = Check(BLACK, i, j);
                bool legalWhites = Check(WHITE, i, j);
                if (legalBlacks && legalWhites) board[i][j] = LEGALBOTH;
                else if (legalBlacks) board[i][j] = LEGALBLACK;
                else if (legalWhites) board[i][j] = LEGALWHITE;
            }
        }
    }
}

// **************** Check *********************************

bool Board::Check(const TileValue& color, const int& i, const int& j) const
{
    const TileValue anticolor = (color == BLACK) ? WHITE : BLACK;
    int x = j;
    int y = i;
    // Up
    for (y = i - 1; (y > 1) && (board[y][j] == anticolor); --y)
    {
        if (board[y - 1][j] == color) return true; 
    }

    // Down
    for (y = i + 1; (y < 7) && (board[y][j] == anticolor); ++y)
    {
        if (board[y + 1][j] == color) return true; 
    }

    // Left
    for (x = j - 1; (x > 1) && (board[i][x] == anticolor); --x)
    {
        if (board[i][x - 1] == color) return true; 
    }

    // Right
    for (x = j + 1; (x < 7) && (board[i][x] == anticolor); ++x)
    {
        if (board[i][x + 1] == color) return true; 
    }

    // Up-Left
    for (x = j - 1, y = i - 1; (x > 1) && (y > 1) && (board[y][x] == anticolor); --x, --y)
    {
        if (board[y - 1][x - 1] == color) return true; 
    }
    
    // Up-Right
    for (x = j + 1, y = i - 1; (x < 7) && (y > 1) && (board[y][x] == anticolor); ++x, --y)
    {
        if (board[y - 1][x + 1] == color) return true; 
    }

    // Down-Left
    for (x = j - 1, y = i + 1; (x > 1) && (y < 7) && (board[y][x] == anticolor); --x, ++y)
    {
        if (board[y + 1][x - 1] == color) return true; 
    }

    // Down-Left
    for (x = j + 1, y = i + 1; (x < 7) && (y < 7) && (board[y][x] == anticolor); ++x, ++y)
    {
        if (board[y + 1][x + 1] == color) return true; 
    }

    return false;
}

// **************** Count *********************************

int Board::CountLegalBlacks() const
{
    int output = 0;
    for (int i = 0; i < 8; ++i)
    {
        for (int j = 0; j < 8; ++j)
        {
            if (board[i][j] == LEGALBLACK) ++output;
            if (board[i][j] == LEGALBOTH) ++output;
        }
    }
    return output;
}

int Board::CountLegalWhites() const
{
    int output = 0;
    for (int i = 0; i < 8; ++i)
    {
        for (int j = 0; j < 8; ++j)
        {
            if (board[i][j] == LEGALWHITE) ++output;
            if (board[i][j] == LEGALBOTH) ++output;
        }
    }
    return output;
}
