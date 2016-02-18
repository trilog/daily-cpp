#ifndef __BOARD__
#define __BOARD__


enum TileValue { EMPTY, BLACK, WHITE, LEGALBLACK, LEGALWHITE, LEGALBOTH };

class Board
{
    public:
             Board            (const string* input);
        void Print            () const;
        void PrintLegalBlacks () const;
        void PrintLegalWhites () const;
        void Analyze          ();
        int  CountLegalBlacks () const;
        int  CountLegalWhites () const;
    private:
        void Print            (const char* legalChar) const;
        bool Check            (const TileValue& color, const int& i, const int& j) const;
        TileValue board[8][8];
};

#endif
