#ifndef GAME_H
#define GAME_H

#include "Chronometer.h"

class Game {
    bool gameRunning;
    int sudokuTable[9][9];
    int playerMovesCount = 0;
    Chronometer timer;

    public:
    Game(){
        gameRunning = true;
        for(int i = 0; i < 9;i++) {
            for(int j = 0; j < 9;j++) {
                sudokuTable[i][j] = 0;
            }
        }
    }
    bool init();
    void end();

    void printARR() {
        timer.startTimer();
        int n = 0;
        for(int i = 0 ; i < 1000000000;i++) {
            n+=(i*2)/2;
        }
        timer.stopTimer();
        timer.printTime();
    }
};

#endif