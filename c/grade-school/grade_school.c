#include "grade_school.h"
#include <string.h>
#include <stdio.h>

/**
 * Check if the given name meets the requirements
 * and is not already presented in the roster
 *
 * @param {roster_t *} roster to search for the duplicated name
 * @param {char *} new_name being checked
 * @returns {uint8_t} true/false
 */
static uint8_t check_name(roster_t * roster, char * new_name){
  if (strlen(new_name) > MAX_NAME_LENGTH)
    return ERROR;

  for (size_t i = 0; i < roster->count; i++){
    if (strcmp(roster->students[i].name, new_name) == 0)
      return ERROR;
  }

  return OK;
}

uint8_t init_roster(roster_t * roster){
  if (!roster) return ERROR;

  roster->count = 0;
  memset(roster->students, 0, sizeof(roster->students));
  return  OK;
}

uint8_t add_student(roster_t * roster, char * name, uint8_t grade){
  if (!roster || !name) return ERROR;
  if (!check_name(roster, name)) return ERROR;

  size_t i = 0;

  for (; i < roster->count; i++){
    if (roster->students[i].grade > grade ||
        (roster->students[i].grade == grade &&
        strcmp(roster->students[i].name, name) > 0))
      break;
  }

  for (size_t j = ++roster->count; j > i; --j)
    roster->students[j] = roster->students[j - 1];

  // Add new student to the roaster
  roster->students[i].grade = grade;
  // The length of the name is already
  // validated so no need to use strncpy
  strcpy(roster->students[i].name, name); 

  // Debug
  //for (uint8_t i = 0; i < roster->count; i++){
  //  printf("name:%s, grade: %i\n", roster->students[i].name, roster->students[i].grade);
  //}

  return OK;
}

roster_t get_grade(roster_t * roster, uint8_t grade){
  roster_t filtered_roster;
  filtered_roster.count = 0;
  memset(filtered_roster.students, 0, sizeof(filtered_roster.students));
  if (!roster) return filtered_roster;

  for (size_t i = 0; i < roster->count; i++){
    if (roster->students[i].grade == grade){
      filtered_roster.students[filtered_roster.count] = roster->students[i];
      filtered_roster.count++;
    }
  }

  return filtered_roster;
}
