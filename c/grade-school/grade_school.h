#ifndef GRADE_SCHOOL_H
#define GRADE_SCHOOL_H

#include <stddef.h>
#include <stdint.h>

#define MAX_NAME_LENGTH 20
#define MAX_STUDENTS    20
#define ERROR           0
#define OK              1

typedef struct {
   uint8_t grade;
   char name[MAX_NAME_LENGTH];
} student_t;

typedef struct {
   size_t count;
   student_t students[MAX_STUDENTS];
} roster_t;

/**
 * Roaster Initialisation
 *
 * @param {roster_t *} pointer to roster to initialise
 * @returns {uint8_t} true/false
 */
uint8_t init_roster(roster_t * roster);

/**
 * Adding student to the given roster
 *
 * @param {roster_t *} pointer to roster students to add
 * @param {char *} name of the student
 * @param {uint8_t} grade of the student
 * @returns {uint8_t} true/false
 */
uint8_t add_student(roster_t * roster, char * name, uint8_t grade);

/**
 * Extract all the students with specific grade from roster
 *
 * @param {roster_t *} pointer to roster students to extract
 * @param {uint8_t} grade requested for extraction
 * @returns {uint8_t} new roster with specific grade students
 */
roster_t get_grade(roster_t * roster, uint8_t grade);

#endif
