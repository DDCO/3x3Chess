#include "game.h"

Game * Game::instance = NULL;

Game::Game()
{
    this->turnCount = 0;
}

Game * Game::getInstance()
{
    if(!Game::instance)
        Game::instance = new Game();
    return Game::instance;
}

void Game::swapPieces()
{

}

void Game::removePiece()
{

}
