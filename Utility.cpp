// Utility.cpp

#include "Utility.h"
#include <ctime>
#include <windows.h>
std::string toUpperCase(const std::string &str)
{
    std::string upperStr;
    for (char c : str)
    {
        if (c >= 'a' && c <= 'z')
        {
            upperStr += c - 'a' + 'A';
        }
        else
        {
            upperStr += c;
        }
    }
    return upperStr;
}

void shuffleWords(std::vector<std::string> &words)
{
    // Seed the random number generator if not already seeded
    static bool seeded = false;
    if (!seeded)
    {
        srand(static_cast<unsigned>(time(0)));
        seeded = true;
    }

    for (size_t i = words.size() - 1; i > 0; --i)
    {
        // Generate a random index from 0 to i
        size_t j = rand() % (i + 1);
        // Swap words[i] with words[j]
        std::swap(words[i], words[j]);
    }
}
void setColor(int color)
{
    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleTextAttribute(hConsole, color);
}
// Variable to keep track of whether the word is shown or not
bool isWordShown = false;