#include "Chronometer.h"

class Game {
    bool gameRunning;
    int sudokuTable[9][9];
    int playerMovesCount = 0;
    Chronometer timeElapsed;

    public:
    Game(){
        for(int i = 0; i < 9;i++) {
            for(int j = 0; j < 9;j++) {
                sudokuTable[i][j] = 0;
            }
        }
    }
    bool init();
    void end();
};