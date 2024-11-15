#include "Word.h"

Word::Word(const std::string& wordText) : text(wordText) {
}

const std::string& Word::getText() const {
    return text;
}