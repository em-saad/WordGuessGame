#include "Grid.h"
#include <iostream>
#include <cstdlib>
#include <ctime>
#include <windows.h> // This includes everything we need for Windows console
#include <conio.h>
#include <chrono>
#include "Utility.h"

Grid::Grid(int gridSize) : size(gridSize)
{
    allocateGrid(size);
}

Grid::~Grid()
{
    deallocateGrid();
}

void Grid::allocateGrid(int gridSize)
{
    grid = new char *[gridSize];
    for (int i = 0; i < gridSize; ++i)
    {
        grid[i] = new char[gridSize];
    }
}

void Grid::deallocateGrid()
{
    for (int i = 0; i < size; ++i)
    {
        delete[] grid[i];
    }
    delete[] grid;
}
void Grid::populateGrid(const std::vector<std::string> &words)
{
    srand(static_cast<unsigned>(time(0)));
    fillEmptyGrid(); // Initialize grid with spaces

    for (const auto &word : words)
    {
        bool placed = false;
        int attempts = 0;
        while (!placed && attempts < 1000)
        { // Limit attempts to avoid infinite loops
            placed = placeWord(word);
            attempts++;
        }
        if (placed)
        {
            placedWords.push_back(word);
            if (debugMode)
            {
                std::cout << "Successfully placed word: " << word << std::endl;
            }
        }
        else
        {
            if (debugMode)
            {
                std::cerr << "Failed to place word: " << word << std::endl;
            }
        }
    }

    fillRandomLetters(); // Fill remaining empty cells with random letters
}

void Grid::fillEmptyGrid()
{
    for (int i = 0; i < size; ++i)
    {
        for (int j = 0; j < size; ++j)
        {
            grid[i][j] = ' '; // Initialize with spaces
        }
    }
}

void Grid::fillRandomLetters()
{
    for (int i = 0; i < size; ++i)
    {
        for (int j = 0; j < size; ++j)
        {
            if (grid[i][j] == ' ') // Only fill cells that are still empty
            {
                grid[i][j] = 'A' + rand() % 26;
            }
        }
    }
}

bool Grid::placeWord(const std::string &word)
{
    int direction = rand() % 3; // 0: Horizontal, 1: Vertical, 2: Diagonal
    int row = rand() % size;
    int col = rand() % size;

    switch (direction)
    {
    case 0: // Horizontal
        if (canPlaceHorizontally(row, col, word))
        {
            placeHorizontally(row, col, word);
            return true;
        }
        break;
    case 1: // Vertical
        if (canPlaceVertically(row, col, word))
        {
            placeVertically(row, col, word);
            return true;
        }
        break;
    case 2: // Diagonal
        if (canPlaceDiagonally(row, col, word))
        {
            placeDiagonally(row, col, word);
            return true;
        }
        break;
    }
    return false;
}

bool Grid::canPlaceHorizontally(int row, int col, const std::string &word)
{
    int wordLength = word.length();
    if (col + wordLength > size)
        return false;

    for (int i = 0; i < wordLength; ++i)
    {
        char currentChar = grid[row][col + i];
        if (currentChar != ' ' && currentChar != word[i])
        {
            return false;
        }
    }
    return true;
}

bool Grid::canPlaceVertically(int row, int col, const std::string &word)
{
    int wordLength = word.length();
    if (row + wordLength > size)
        return false;

    for (int i = 0; i < wordLength; ++i)
    {
        char currentChar = grid[row + i][col];
        if (currentChar != ' ' && currentChar != word[i])
        {
            return false;
        }
    }
    return true;
}

bool Grid::canPlaceDiagonally(int row, int col, const std::string &word)
{
    int wordLength = word.length();
    if (row + wordLength > size || col + wordLength > size)
        return false;

    for (int i = 0; i < wordLength; ++i)
    {
        char currentChar = grid[row + i][col + i];
        if (currentChar != ' ' && currentChar != word[i])
        {
            return false;
        }
    }
    return true;
}

void Grid::placeHorizontally(int row, int col, const std::string &word)
{
    for (int i = 0; i < word.length(); ++i)
    {
        grid[row][col + i] = word[i];
    }
}

void Grid::placeVertically(int row, int col, const std::string &word)
{
    for (int i = 0; i < word.length(); ++i)
    {
        grid[row + i][col] = word[i];
    }
}

void Grid::placeDiagonally(int row, int col, const std::string &word)
{
    for (int i = 0; i < word.length(); ++i)
    {
        grid[row + i][col + i] = word[i];
    }
}

void Grid::displayGrid()
{
    setColor(CYAN);
    std::cout << "\n   ╔";
    for (int i = 0; i < size; i++)
    {
        std::cout << "═══";
    }
    std::cout << "═╗\n";

    // Column numbers
    std::cout << "   ║ ";
    setColor(YELLOW);
    for (int i = 0; i < size; i++)
    {
        std::cout << i << "  ";
    }
    setColor(CYAN);
    std::cout << "║\n";

    // Separator line
    std::cout << "   ╠";
    for (int i = 0; i < size; i++)
    {
        std::cout << "═══";
    }
    std::cout << "═╣\n";

    // Grid content
    for (int i = 0; i < size; i++)
    {
        setColor(YELLOW);
        std::cout << " " << i << " ";
        setColor(CYAN);
        std::cout << "║ ";
        for (int j = 0; j < size; j++)
        {
            if (grid[i][j] == '*')
            {
                setColor(GREEN); // Found words in green
            }
            else
            {
                setColor(WHITE); // Regular letters in white
            }
            std::cout << grid[i][j] << "  ";
        }
        setColor(CYAN);
        std::cout << "║\n";
    }

    // Bottom border
    std::cout << "   ╚";
    for (int i = 0; i < size; i++)
    {
        std::cout << "═══";
    }
    std::cout << "═╝\n\n";
    setColor(RESET); // Reset color
}

int Grid::getSize() const
{
    return size;
}

char Grid::getCharAt(int row, int col) const
{
    if (row >= 0 && row < size && col >= 0 && col < size)
    {
        return grid[row][col];
    }
    return '\0';
}

bool Grid::checkWord(const std::string &word)
{
    // Check if the word has already been found
    for (const auto &foundWord : foundWords)
    {
        if (word == foundWord)
        {
            return true;
        }
    }
    return false;
}
void Grid::markWord(const std::string &word)
{
    // Iterate over the grid to find and mark the word
    int size = getSize();
    int wordLength = word.length();

    // Check horizontally
    for (int row = 0; row < size; ++row)
    {
        for (int col = 0; col <= size - wordLength; ++col)
        {
            int i;
            for (i = 0; i < wordLength; ++i)
            {
                if (grid[row][col + i] != word[i])
                {
                    break;
                }
            }
            if (i == wordLength)
            {
                // Mark the word
                for (i = 0; i < wordLength; ++i)
                {
                    grid[row][col + i] = '*'; // Mark with an asterisk
                }
                foundWords.push_back(word);
                return;
            }
        }
    }

    // Check vertically
    for (int col = 0; col < size; ++col)
    {
        for (int row = 0; row <= size - wordLength; ++row)
        {
            int i;
            for (i = 0; i < wordLength; ++i)
            {
                if (grid[row + i][col] != word[i])
                {
                    break;
                }
            }
            if (i == wordLength)
            {
                // Mark the word
                for (i = 0; i < wordLength; ++i)
                {
                    grid[row + i][col] = '*'; // Mark with an asterisk
                }
                foundWords.push_back(word);
                return;
            }
        }
    }

    // Check diagonally (top-left to bottom-right)
    for (int row = 0; row <= size - wordLength; ++row)
    {
        for (int col = 0; col <= size - wordLength; ++col)
        {
            int i;
            for (i = 0; i < wordLength; ++i)
            {
                if (grid[row + i][col + i] != word[i])
                {
                    break;
                }
            }
            if (i == wordLength)
            {
                // Mark the word
                for (i = 0; i < wordLength; ++i)
                {
                    grid[row + i][col + i] = '*'; // Mark with an asterisk
                }
                foundWords.push_back(word);
                return;
            }
        }
    }

    // Check diagonally (bottom-left to top-right)
    for (int row = wordLength - 1; row < size; ++row)
    {
        for (int col = 0; col <= size - wordLength; ++col)
        {
            int i;
            for (i = 0; i < wordLength; ++i)
            {
                if (grid[row - i][col + i] != word[i])
                {
                    break;
                }
            }
            if (i == wordLength)
            {
                // Mark the word
                for (i = 0; i < wordLength; ++i)
                {
                    grid[row - i][col + i] = '*'; // Mark with an asterisk
                }
                foundWords.push_back(word);
                return;
            }
        }
    }
}