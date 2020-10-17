#include "sudoku_class.h"

int main() {
    Sudoku match;
    match.fillSudokuTable();
    while(match.init()) {
        match.printTable();
        match.end();
    }
}