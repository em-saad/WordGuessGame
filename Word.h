#ifndef WORD_H
#define WORD_H

#include <string>

class Word {
public:
    Word(const std::string& text);
    const std::string& getText() const;

private:
    std::string text;
};

#endif // WORD_H