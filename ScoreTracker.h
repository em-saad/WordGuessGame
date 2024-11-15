#ifndef SCORETRACKER_H
#define SCORETRACKER_H

#include "Player.h"
#include <vector>
#include <string>

class ScoreTracker {
public:
    ScoreTracker();
    void updateScore(int points);
    void saveHighScore(const Player& player);
    void loadHighScores();
    void displayHighScores();

    static const int MAX_HIGH_SCORES = 5;

private:
    std::vector<std::pair<std::string, int>> highScores;
    void sortHighScores();
    void loadFromFile();
    void saveToFile();
};

#endif // SCORETRACKER_H