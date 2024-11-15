#include "WordValidator.h"

WordValidator::WordValidator(const std::vector<std::string> &wordList, const Grid &gameGrid)
    : wordList(wordList), grid(gameGrid)
{
}

bool WordValidator::isValidWord(const std::string &word)
{
    for (const auto &validWord : wordList)
    {
        if (word == validWord)
        {
            return true;
        }
    }
    return false;
}

bool WordValidator::isInGrid(const std::string &word)
{
    return searchHorizontal(word) || searchVertical(word) || searchDiagonal(word);
}

#include <iostream>

bool WordValidator::searchHorizontal(const std::string &word)
{
    int size = grid.getSize();
    int wordLength = word.length();

    for (int row = 0; row < size; ++row)
    {
        for (int col = 0; col <= size - wordLength; ++col)
        {
            int i;
            for (i = 0; i < wordLength; ++i)
            {
                if (grid.getCharAt(row, col + i) != word[i])
                {
                    break;
                }
            }
            if (i == wordLength)
            {
                std::cout << "Found horizontally: " << word << " at (" << row << "," << col << ")\n"; // Debug statement
                return true;
            }
        }
    }
    return false;
}

bool WordValidator::searchVertical(const std::string &word)
{
    int size = grid.getSize();
    int wordLength = word.length();

    for (int col = 0; col < size; ++col)
    {
        for (int row = 0; row <= size - wordLength; ++row)
        {
            int i;
            for (i = 0; i < wordLength; ++i)
            {
                if (grid.getCharAt(row + i, col) != word[i])
                {
                    break;
                }
            }
            if (i == wordLength)
            {
                std::cout << "Found vertically: " << word << " at (" << row << "," << col << ")\n"; // Debug statement
                return true;
            }
        }
    }
    return false;
}

bool WordValidator::searchDiagonal(const std::string &word)
{
    int size = grid.getSize();
    int wordLength = word.length();
    // Top-left to bottom-right (\)
    for (int row = 0; row <= size - wordLength; ++row)
    {
        for (int col = 0; col <= size - wordLength; ++col)
        {
            int i;
            for (i = 0; i < wordLength; ++i)
            {
                if (grid.getCharAt(row + i, col + i) != word[i])
                {
                    break;
                }
            }
            if (i == wordLength)
            {
                std::cout << "Found diagonally (\\): " << word << " at (" << row << "," << col << ")\n"; // Debug statement
                return true;
            }
        }
    }
    // Bottom-left to top-right (/)
    for (int row = wordLength - 1; row < size; ++row)
    {
        for (int col = 0; col <= size - wordLength; ++col)
        {
            int i;
            for (i = 0; i < wordLength; ++i)
            {
                if (grid.getCharAt(row - i, col + i) != word[i])
                {
                    break;
                }
            }
            if (i == wordLength)
            {
                std::cout << "Found diagonally (/): " << word << " at (" << row - i << "," << col + i << ")\n"; // Debug statement
                return true;
            }
        }
    }
    return false;
}