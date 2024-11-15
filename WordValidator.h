#ifndef WORDVALIDATOR_H
#define WORDVALIDATOR_H

#include <vector>
#include <string>
#include "Grid.h"

class WordValidator {
public:
    WordValidator(const std::vector<std::string>& wordList, const Grid& gameGrid);

    bool isValidWord(const std::string& word);
    bool isInGrid(const std::string& word);

private:
    std::vector<std::string> wordList;
    const Grid& grid;

    bool searchHorizontal(const std::string& word);
    bool searchVertical(const std::string& word);
    bool searchDiagonal(const std::string& word);
};

#endif // WORDVALIDATOR_H