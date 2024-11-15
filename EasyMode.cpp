#include "EasyMode.h"
#include <iostream>
#include <fstream>
#include <cstdlib>
#include <conio.h>
#include <windows.h>
#include <algorithm>
#include <ctime>
#include <string>
#include "Utility.h"
#include "ScoreTracker.h"

EasyMode::EasyMode() : player("Player", 0, 5)
{
    loadWords();
}
void EasyMode::loadWords()
{
    std::ifstream file("easy_words.txt");
    if (file.is_open())
    {
        std::string word;
        while (file >> word)
        {
            word = toUpperCase(word);
            words.push_back(word);
        }

        file.close();

        // Shuffle the words
        shuffleWords(words);
    }
    else
    {
        std::cout << "Error: Unable to open easy_words.txt\n";
    }
}

void EasyMode::play()
{
    std::cout << "Enter your name: ";
    std::string name;
    std::cin >> name;
    player.setName(name);

    for (int level = 1; level <= 3 && player.getRemainingChances() > 0; ++level)
    {
        startLevel(level);
    }

    // Game Over Screen
    system("CLS");
    std::cout << "\n=== GAME OVER ===\n";
    std::cout << "Your Score: " << player.getScore() << "\n";

    ScoreTracker scoreTracker;
    scoreTracker.saveHighScore(player);
    scoreTracker.displayHighScores();

    std::cout << "\nPress any key to return to main menu...";
    _getch();
}

void EasyMode::loadedWords()
{
    // After loading words
    std::cout << "Loaded words:\n";
    for (const auto &w : words)
    {
        std::cout << w << std::endl;
    }
}

void EasyMode::startLevel(int levelNumber)
{
    system("CLS");
    std::cout << "Easy Mode - Level " << levelNumber << "\n";

    int gridSize = (levelNumber == 1) ? 10 : (levelNumber == 2) ? 15
                                                                : 20;
    int wordsToGuessCount = (levelNumber == 1) ? 3 : (levelNumber == 2) ? 5
                                                                        : 7;

    // Ensure there are enough words
    if (words.size() < wordsToGuessCount)
    {
        std::cerr << "Not enough words available for this level!\n";
        return;
    }

    // Shuffle the words vector
    // shuffleWords(words);

    // Select words for this level
    std::vector<std::string> wordsToGuess(words.begin(), words.begin() + wordsToGuessCount);

    // Remove selected words from words vector to prevent repetition
    words.erase(words.begin(), words.begin() + wordsToGuessCount);

    // Initialize remainingWords
    remainingWords = wordsToGuess;

    Grid grid(gridSize);
    grid.enableDebug(false);
    grid.populateGrid(wordsToGuess);

    WordValidator validator(wordsToGuess, grid);

    int guessedWords = 0;
    while (guessedWords < wordsToGuessCount && player.getRemainingChances() > 0)
    {
        grid.displayGrid();
        showGameStatus();
        processGuess(guessedWords, wordsToGuessCount, validator, grid);
    }

    if (player.getRemainingChances() == 0)
    {
        std::cout << "No remaining chances. Game Over.\n";
    }
    else
    {
        std::cout << "Level " << levelNumber << " complete!\n";
        Sleep(1500);
    }
}

void EasyMode::processGuess(int &guessedWords, int wordsToGuessCount, WordValidator &validator, Grid &grid)
{
    std::string guess;
    std::cout << "Enter word (2-4 letters): ";
    std::cin >> guess;
    guess = toUpperCase(guess);

    if (validator.isValidWord(guess))
    {
        if (validator.isInGrid(guess))
        {
            if (!grid.checkWord(guess))
            {
                std::cout << "Correct! Word found.\n";
                player.updateScore(10);
                guessedWords++;
                grid.markWord(guess);

                // Remove the guessed word from remainingWords
                auto it = std::find(remainingWords.begin(), remainingWords.end(), guess);
                if (it != remainingWords.end())
                {
                    remainingWords.erase(it);
                }
            }
            else
            {
                std::cout << "Word already found.\n";
            }
        }
        else
        {
            std::cout << "Word not in grid.\n";
            player.decreaseChance();
        }
    }
    else
    {
        std::cout << "Invalid word.\n";
        player.decreaseChance();
    }
    Sleep(1500);
    system("CLS");
}
void EasyMode::showGameStatus()
{
    setColor(CYAN);
    std::cout << "╔════════════════════════════════╗\n";
    std::cout << "║         GAME STATUS            ║\n";
    std::cout << "╠════════════════════════════════╣\n";

    setColor(WHITE);
    std::cout << "║ Remaining Chances: ";
    setColor(YELLOW);
    std::cout << player.getRemainingChances();
    setColor(CYAN);
    std::cout << "           ║\n";

    setColor(WHITE);
    std::cout << "║ Words Remaining: ";
    setColor(YELLOW);
    std::cout << remainingWords.size();
    setColor(CYAN);
    std::cout << "             ║\n";

    setColor(WHITE);
    std::cout << "║ Score: ";
    setColor(GREEN);
    std::cout << player.getScore();
    setColor(CYAN);
    if (player.getScore() < 10)
    {
        std::cout << "                       ║\n";
    }
    else if (player.getScore() < 100)
    {
        std::cout << "                      ║\n";
    }
    else if (player.getScore() < 1000)
    {
        std::cout << "                     ║\n";
    }
    else
    {
        std::cout << "                       ║\n";
    }
    std::cout << "╚════════════════════════════════╝\n\n";
    // Display Remaining Words
    setColor(WHITE);
    std::cout << "║ Remaining Words (Testing): ";
    if (isWordShown)
    {
        for (const auto &word : remainingWords)
        {
            setColor(GREEN);
            std::cout << word << " ";
        }
        std::cout << "\n";
    }

    setColor(RESET);
}