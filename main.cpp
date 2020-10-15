#include "Game.h"

int main() {
    Game match;
    while(match.init()) {
        match.printARR();
        match.end();
    }
}