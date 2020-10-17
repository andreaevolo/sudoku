#ifndef GAME_H
#define GAME_H

#include "chronometer_class.h"
#include "coordinates_struct.h"

class Game {
    bool game_running_ = true;
    int sudoku_table_[9][9];
    int player_moves_count_ = 0;
    Chronometer timer_;
    // check if the number insert by the user is unique to the column
    bool checkColumn(short int x, short int y);
    // check if the number insert by the user is unique to the row
    bool checkRow(short int x, short int y);
    // check if the number insert by the user is unique in the 3 x 3 grid
    bool checkGrid(short int x, short int y);

    // verify both single value and coordinates before insert them in the grid
    short int inputCellValue();
    Coordinates inputCoordinates();
    void askUserInput();
    public:
    Game(){}
   
    bool init();
    void fillSudokuTable();
    void end();
    void printTable();
};

#endif