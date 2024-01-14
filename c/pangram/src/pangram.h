#ifndef PANGRAM_H
#define PANGRAM_H

#include <stdbool.h>

bool is_pangram(const char *sentence);
bool is_letter(char c);
char to_lower(char c);

#endif
