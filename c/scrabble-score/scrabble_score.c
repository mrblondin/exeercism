#include "scrabble_score.h"
#include <ctype.h>
#include <stddef.h>

static letter_t LETTERS[] = {
    {'A', 1}, {'E', 1}, {'I', 1}, {'O', 1}, {'U', 1}, {'L', 1}, {'N', 1}, {'R', 1}, {'S', 1}, {'T', 1},
    {'D', 2}, {'G', 2},
    {'B', 3}, {'C', 3}, {'M', 3}, {'P', 3},
    {'F', 4}, {'H', 4}, {'V', 4}, {'W', 4}, {'Y', 4},
    {'K', 5},
    {'J', 8}, {'X', 8},
    {'Q', 10}, {'Z', 10}
};

static size_t length = sizeof(LETTERS) / sizeof(letter_t);

unsigned int score(const char *word){
    int output = 0;

    while (*word){
        char ch = toupper(*word++);
        for (size_t index = 0; index < length; ++index){
            if (LETTERS[index].letter == ch)
                output += LETTERS[index].value;
        }
    }
    return output;
}
