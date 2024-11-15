// Grid.h

#ifndef GRID_H
#define GRID_H

#include <vector>
#include <string>

class Grid
{
public:
    Grid(int size);
    ~Grid();
    void allocateGrid(int size);
    void deallocateGrid();
    void populateGrid(const std::vector<std::string> &words);
    void fillEmptyGrid();
    void displayGrid();
    bool checkWord(const std::string &word);
    void markWord(const std::string &word);
    int getSize() const;
    char getCharAt(int row, int col) const;

private:
    int size;
    char **grid;
    std::vector<std::string> placedWords;
    std::vector<std::string> foundWords;
    void fillRandomLetters();
    bool placeWord(const std::string &word);
    bool canPlaceHorizontally(int row, int col, const std::string &word);
    bool canPlaceVertically(int row, int col, const std::string &word);
    bool canPlaceDiagonally(int row, int col, const std::string &word);
    void placeHorizontally(int row, int col, const std::string &word);
    void placeVertically(int row, int col, const std::string &word);
    void placeDiagonally(int row, int col, const std::string &word);
    
    // Debug flag
    bool debugMode = false;

public:
    // Function to enable debug mode
    void enableDebug(bool enable) { debugMode = enable; }
};

#endif // GRID_H