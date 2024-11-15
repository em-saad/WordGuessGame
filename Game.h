#ifndef GAME_H
#define GAME_H

#include <string>

class Game
{
public:
    Game();
    void displayTitle();
    void displayMenu();
    void startGame();
    void showInstructions();
    void showHighScores();
    void aboutUs();
    void exitGame();
    ~Game();

private:
    void clearScreen();
    void pause();
    void setColor(int color);
};

#endif // GAME_H