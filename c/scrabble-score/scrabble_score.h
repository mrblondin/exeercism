#ifndef SCRABBLE_SCORE_H
#define SCRABBLE_SCORE_H

typedef struct {
    char letter;
    int value;
} letter_t;

unsigned int score(const char *word);

#endif
