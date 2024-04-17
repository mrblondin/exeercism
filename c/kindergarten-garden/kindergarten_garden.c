#include "kindergarten_garden.h"
#include <string.h>
#include <stdlib.h>

const char LOOKUP[] = {'C', 'G', 'R', 'V'};
const char * NAMES[] = {"Alice", "Bob", "Charlie", "David", "Eve", "Fred", "Ginny",
                        "Harriet", "Ileana", "Joseph", "Kincaid", "Larry"};
const int NAMES_Q = sizeof(NAMES) / sizeof(*NAMES);
const int PLANTS_Q = sizeof(LOOKUP) / sizeof(*LOOKUP);
#define MAX_DIAG_LENGTH 50

static int get_name_index(const char *name){
    int index_name = -1;
    for (int index = 0; index < NAMES_Q; ++index){
        if (strcmp(name, NAMES[index]) == 0){
            index_name = index;
            break;
        }
    }
    return index_name;
}

static void get_keys(char *diagram, int index, char **keys){
    char buf[MAX_DIAG_LENGTH + 1];
    memset(buf, 0, MAX_DIAG_LENGTH + 1);
    strncpy(buf, diagram, strlen(diagram));
    const char delimeter[2] = "\n";
    char * token;

    token = strtok(buf, delimeter);

    while (token != NULL){
        memcpy(*keys + strlen(*keys), &token[index * 2], 2);
        token = strtok(NULL, delimeter);
    }
}

static int translate_key(char key){
    for (int index = 0; index < PLANTS_Q; ++index){
        if (LOOKUP[index] == key) 
            return index;
    }
    return 0;
}

plants_t plants(const char * diagram, const char * student){
    plants_t plants = {.plants = {0, 1, 2, 3}};
    
    int index_name = get_name_index(student);

    char * keys = calloc(PLANTS_Q, sizeof(char));
    get_keys((char *)diagram, index_name, &keys);

    char * p = keys;
    int index = 0;
    while (*p){ plants.plants[index++] = translate_key(*p++); }
    free(keys);

    return plants;
}


