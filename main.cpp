#include "game_class.h"

int main() {
    Game match;
    match.fillSudokuTable();
    while(match.init()) {
        match.printTable();
        match.end();
    }
}