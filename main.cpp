#include "sudoku_class.h"
#include <ctime>

int main()
{
    srand(time(0));
    Sudoku match;
    match.fillSudokuTable();

    while (match.init())
    {
        std::cout << "Enter -1 to give up." << std::endl;
        match.printTable();
        // match.end();
    }
}