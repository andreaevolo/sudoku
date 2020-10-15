#include "Game.h"


bool Game::init() {
    return gameRunning;
}
void Game::end() {
    gameRunning = false;
}