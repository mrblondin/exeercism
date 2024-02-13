#include "hello_world.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h> 

const char *hello(void)
{
    //html_escape("Hix How < Are > You \" Dear? ' Where are you");
    char* value = "Hix><  How < Are > You \"  > Dear? ' Where \" are ' you";
    char* result;  
    const char* oldA[] = {"<", ">", "\"", "'", NULL};
    const char* newA[] = {"&lt;", "&gt;", "&quot;", "&#x27;", NULL};
    result = replaceWord(value, oldA, newA);
    printf("%s", result);
    free(result);
	return "Hello <script> '  \" World!";
}

// Function to replace a string with another
// string
char* replaceWord(const char* s, const char** oldA, const char** newA)
{
    char* result;
    int i, j = 0, cnt;
    int newWlen, oldWlen, newSize = 0;

    while(oldA[j] != NULL && newA[j] != NULL){
        newWlen = strlen(newA[j]);
        oldWlen = strlen(oldA[j]);

        cnt = 0;
        // Counting the number of times old word
        for (i = 0; s[i] != '\0'; i++) {
            if (strstr(&s[i], oldA[j]) == &s[i]) {
                cnt++;

                // Jumping to index after the old word.
                i += oldWlen - 1;
            }
        }
        newSize = newSize == 0 ? i : newSize;
        printf("cnt: %i, i: %i, j: %i\n", cnt, i, j);
        newSize += cnt*(newWlen - oldWlen); 
        j++;
    }

    // Making new string of enough length
    result = (char*)malloc(newSize + 1);

    j = 0;
    char ss[newSize];
    //memset(ss, '\0', sizeof(ss));
    strcpy(ss, s);
    while(oldA[j] != NULL && newA[j] != NULL){
        newWlen = strlen(newA[j]);
        oldWlen = strlen(oldA[j]);

        i = 0;
        int k = 0;
        while (ss[i] != '\0') {
            // compare the substring with the result
            if (strstr(&ss[i], oldA[j]) == &ss[i]) {
                strcpy(&result[k], newA[j]);
                k += newWlen;
                i += oldWlen;
            }
            else{
                result[k] = ss[i];
                i++;
                k++;
            }
        }
        strcpy(ss, result);
        result[k] = '\0'; j++;
    }

    return result;
}

