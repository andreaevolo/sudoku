#include "sudoku_class.h"
#include <ctime>

int main()
{
    srand(time(0));
    Sudoku match;
    match.fillSudokuTable();
    while (match.init())
    {
        match.printTable();
        match.end();
    }
}