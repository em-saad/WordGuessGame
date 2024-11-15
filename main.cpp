#include "Game.h"
#include <iostream>
#include <time.h>
#include "Utility.h"

int main()
{
    // Seed the random number generator,for better random numbers
    srand(static_cast<unsigned>(time(0)));
    isWordShown = true;
    Game game;
    game.displayMenu();
    return 0;
}