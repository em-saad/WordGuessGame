#include "ScoreTracker.h"
#include <fstream>
#include <iostream>
#include <algorithm>

ScoreTracker::ScoreTracker() {
    loadFromFile();
}

void ScoreTracker::updateScore(int points) {
    // Method can be used if additional score tracking is needed
}

void ScoreTracker::saveHighScore(const Player& player) {
    highScores.push_back(std::make_pair(player.getName(), player.getScore()));
    sortHighScores();
    if (highScores.size() > MAX_HIGH_SCORES) {
        highScores.resize(MAX_HIGH_SCORES);
    }
    saveToFile();
}

void ScoreTracker::loadHighScores() {
    loadFromFile();
}

void ScoreTracker::displayHighScores() {
    std::cout << "Top " << MAX_HIGH_SCORES << " High Scores:\n";
    for (const auto& score : highScores) {
        std::cout << score.first << " - " << score.second << "\n";
    }
}

void ScoreTracker::sortHighScores() {
    std::sort(highScores.begin(), highScores.end(),
              [](const std::pair<std::string, int>& a, const std::pair<std::string, int>& b) {
                  return b.second < a.second; // Descending order
              });
}

void ScoreTracker::loadFromFile() {
    highScores.clear();
    std::ifstream infile("easy_highscores.txt");
    if (infile.is_open()) {
        std::string name;
        int score;
        while (infile >> name >> score) {
            highScores.emplace_back(name, score);
        }
        infile.close();
    }
}

void ScoreTracker::saveToFile() {
    std::ofstream outfile("easy_highscores.txt", std::ios::trunc);
    if (outfile.is_open()) {
        for (const auto& score : highScores) {
            outfile << score.first << " " << score.second << "\n";
        }
        outfile.close();
    }
}