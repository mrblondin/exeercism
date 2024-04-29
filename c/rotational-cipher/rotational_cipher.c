#include "rotational_cipher.h"
#include <stddef.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define ALPHA_SIZE 26

char *rotate(const char *text, int shift_key){ 
    int length = strlen(text);
    char *output = calloc(length + 1, sizeof(char));
    if (!output) return NULL;

    shift_key = shift_key % ALPHA_SIZE;
    
    int index = 0;
    while(*text){
        char ch = *text++;
        if (isalpha(ch)){
            int ground = isupper(ch) ? 'A' : 'a';    
            ch = (ch + shift_key - ground) % ALPHA_SIZE + ground;
        }
        output[index++] = ch;
    }

    return output;
}
