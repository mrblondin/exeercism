#include "isogram.h"
#include <string.h> 

bool is_isogram(const char phrase[]){
    if (phrase == NULL)
        return false;

    for(int i = 0; phrase[i] != '\0'; i++){
        if (!is_letter(phrase[i]))
            continue;
        for(int j = i + 1; phrase[j] != '\0'; j++){
            if (!is_letter(phrase[j]))
                continue;
            //check also that chars are similar despite of register
            if(phrase[i] == phrase[j] || (phrase[i] | 0x60) == phrase[j] || phrase[i] == (phrase[j] | 0x60))
            return false; 
            
        }
    }
    
    return true;
}

bool is_letter(char c){
    if ((c >= 'A' && c <= 'Z') || (c >= 'a' && c <= 'z'))
        return true;
    else
        return false;
}
