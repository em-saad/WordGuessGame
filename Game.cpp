// Game.cpp
#include "Game.h"
#include <iostream>
#include <windows.h> // For system("CLS"), Sleep()
#include <conio.h>
#include "EasyMode.h"
#include "ScoreTracker.h" // Include ScoreTracker for high scores

// Color definitions
#define RESET 7
#define RED 12
#define GREEN 10
#define BLUE 9
#define YELLOW 14
#define MAGENTA 13
#define CYAN 11
#define WHITE 15

Game::Game()
{
    // Set console to UTF-8
    system("chcp 65001");
}

Game::~Game()
{
    // Destructor logic (if any)
}

void Game::setColor(int color)
{
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), color);
}

void Game::displayTitle()
{
    clearScreen();
    setColor(CYAN);
    std::cout << "\n╔═══════════════════════════════════╗\n";
    setColor(YELLOW);
    std::cout << "║      WORD SEARCH PUZZLE GAME      ║\n";
    setColor(CYAN);
    std::cout << "╚═══════════════════════════════════╝\n\n";
    setColor(RESET);
}

void Game::displayMenu()
{
    int choice;
    do
    {
        displayTitle();
        std::cout << "1. Start Game\n";
        std::cout << "2. Instructions\n";
        std::cout << "3. Highest Scores\n";
        std::cout << "4. About Us\n";
        std::cout << "5. Exit\n";
        std::cout << "\nSelect an option (1-5): ";
        std::cin >> choice;

        switch (choice)
        {
        case 1:
            startGame();
            break;
        case 2:
            showInstructions();
            break;
        case 3:
            showHighScores();
            break;
        case 4:
            aboutUs();
            break;
        case 5:
            exitGame();
            break;
        default:
            std::cout << "Invalid option. Please try again.\n";
            pause();
            break;
        }
    } while (choice != 5);
}

void Game::startGame()
{
    system("CLS");
    // Initialize and start Easy Mode
    EasyMode easyMode;
    easyMode.play();
}

void Game::showInstructions()
{
     clearScreen();
    std::cout << "\n=== WORD SEARCH GAME - INSTRUCTIONS ===\n";
    std::cout << "1. Find hidden words in the grid\n";
    std::cout << "2. Words can be:\n";
    std::cout << "   - Horizontal (left to right)\n";
    std::cout << "   - Vertical (top to bottom)\n";
    std::cout << "   - Diagonal (top left to bottom right)\n";
    std::cout << "\nHidden Words Lengths:\n";
    std::cout << "- 2-4 letters\n"; // Updated to reflect Easy Mode specifications
    std::cout << "\n===============================\n\n";
    pause();
}

void Game::showHighScores()
{
    clearScreen();
    ScoreTracker scoreTracker;
    scoreTracker.displayHighScores();
    pause();
}

void Game::aboutUs()
{
    clearScreen();
    std::cout << "About Us:\n";
    std::cout << "This game is developed by Saad ... .\n";
    pause();
}

void Game::exitGame()
{
    clearScreen();
    std::cout << "Thank you for playing!\n";
    Sleep(2000);
    exit(0);
}

void Game::clearScreen()
{
    system("CLS");
}

void Game::pause()
{
    std::cout << "\nPress any key to continue...";
    _getch();
}