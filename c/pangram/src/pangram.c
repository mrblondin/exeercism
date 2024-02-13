#include "pangram.h"
#include <string.h>

bool is_pangram(const char *sentence){
    if (sentence == NULL)
        return false;
    
    int lettersLeft = 26;
    int letters[lettersLeft]; 
    
    //fill in the array with letters
    for(int i = 0; i < lettersLeft; i++)
        letters[i] = 97 + i; 
    
    //find letters in array and decrease lettersLeft
    for(int i = 0; sentence[i] != '\0'; i++) {
        if(is_letter(sentence[i])){
            int let = (int)to_lower(sentence[i]);
            for(int j = 0; j < lettersLeft; j++) {
                if(letters[j] == let) {
                   letters[j] = letters[--lettersLeft];
                }
            }
        }
    }

    return lettersLeft == 0 ? true : false;
}

bool is_letter(char c){
    if ((c >= 'A' && c <= 'Z') || (c >= 'a' && c <= 'z'))
        return true;
    else
        return false;
}

char to_lower(char c){
    const char OFFSET = 'A' - 'a';
    if (c >= 'A' && c <= 'Z')
        return c -= OFFSET;
    return c;
}

