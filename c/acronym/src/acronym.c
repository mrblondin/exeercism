#include "acronym.h"
#include <string.h>
#include <stdlib.h>

char *abbreviate(const char *phrase){
    if (phrase == NULL)
        return NULL;
    
    int j = 0;    
    bool isNewLetter = true;
    char * abbr = (char *) malloc(sizeof(char));   

    for(int i = 0; phrase[i] != '\0'; i++){
        if (!is_letter(phrase[i])){
            if(phrase[i] == ' ' || phrase[i] == '-')
                isNewLetter = true; 
            continue;
        }
        else{
            if(isNewLetter){
                abbr[j] = to_upper(phrase[i]);
                isNewLetter = false;
                j++;
                abbr = (char *) realloc(abbr, (j + 1) * sizeof(char));
            }
        }
    }

    if(j > 0)
        abbr[j] = '\0';
    else
        return NULL;

    return abbr;    
}

bool is_letter(char c){
    if ((c >= 'A' && c <= 'Z') || (c >= 'a' && c <= 'z'))
        return true;
    else
        return false;
}

char to_upper(char c){
    const char OFFSET = 'a' - 'A';
    if (c >= 'a' && c <= 'z')
        return c -= OFFSET;
    return c;
}
