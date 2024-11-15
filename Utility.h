// Utility.h

#ifndef UTILITY_H
#define UTILITY_H

#include <string>
#include <vector>

std::string toUpperCase(const std::string &str);
extern bool isWordShown;
void shuffleWords(std::vector<std::string> &words);
void setColor(int color);
// Color definitions
#define RESET 7
#define RED 12
#define GREEN 10
#define BLUE 9
#define YELLOW 14
#define MAGENTA 13
#define CYAN 11
#define WHITE 15

#endif // UTILITY_H