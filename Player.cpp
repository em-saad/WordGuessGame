#include "Player.h"

Player::Player(const std::string& playerName, int initialScore, int chances)
    : name(playerName), score(initialScore), remainingChances(chances) {
}

const std::string& Player::getName() const {
    return name;
}

int Player::getScore() const {
    return score;
}

int Player::getRemainingChances() const {
    return remainingChances;
}

void Player::setName(const std::string& newName) {
    name = newName;
}

void Player::updateScore(int points) {
    score += points;
}

void Player::decreaseChance() {
    if (remainingChances > 0) {
        remainingChances--;
    }
}