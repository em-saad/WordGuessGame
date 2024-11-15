#ifndef PLAYER_H
#define PLAYER_H

#include <string>

class Player {
public:
    Player(const std::string& name, int initialScore, int chances);

    const std::string& getName() const;
    int getScore() const;
    int getRemainingChances() const;

    void setName(const std::string& newName);
    void updateScore(int points);
    void decreaseChance();

private:
    std::string name;
    int score;
    int remainingChances;
};

#endif // PLAYER_H