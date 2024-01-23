#include "word_count.h"
#include <string.h>
#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

int word_count(const char *input_text, word_count_word_t * words){
    int i = 0, n = 0;
    char * token;
    char * rest = strdup(input_text);
    while((token = strtok_r(rest, " ,!:@$%^&.\n\t", &rest))){
        bool isNew = true;
            char * _token = to_lower_and_no_quotes(token);
        for(int j = 0; j < n; j++){
            if(strcmp(_token, words[j].text) == 0){
                isNew = false;
                words[j].count++;
                break;
            }
        }
        if (isNew){
            //ignore the rest of strtok_r
            if (n < 0)
                continue;
            //if too many words
            if (strlen(_token) > MAX_WORD_LENGTH){
                n = EXCESSIVE_LENGTH_WORD;
                continue;
            }
            if (n >= MAX_WORDS){
                n = EXCESSIVE_NUMBER_OF_WORDS;
                continue;
            }
            strncpy(words[n].text, _token, STRING_SIZE); 
            words[n].count = 1;
            n++;
        }
        i++;
    }
    free(rest);
    
    return n;
}

char * to_lower_and_no_quotes(char * str){
    const char OFFSET = 'a' - 'A';
    char lastChar = '\0';
    for(char *c = str; *c; ++c){
        if (*c >= 'A' && *c <= 'Z')
            *c += OFFSET;
        //remove first character '
        if (lastChar == '\0' && *c == '\''){
            memmove(str, str + 1, strlen(str));
        }
        lastChar = *c;
    }
   
    //remove last characher '
    if (lastChar == '\'')
        str[strlen(str) - 1] = '\0'; 
   
    return str;
}
