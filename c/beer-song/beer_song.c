#include "beer_song.h"
#include <assert.h>
#include <stdio.h>

#define MAX_LINE_LENGTH 1024

void recite(uint8_t start_bottles, uint8_t take_down, char **song){
  assert(take_down && song);

  char template1[] = "%i bottle%s of beer on the wall, %i bottle%s of beer.";
  char template1_0[] = "No more bottles of beer on the wall, no more bottles of beer.";
  char template2[] = "%s, %i bottle%s of beer on the wall.";
  char template2_0[] = "Take it down and pass it around, no more bottles of beer on the wall.";

  for (size_t i = 0; i < take_down; i++){
    if (i)
      song++;

    if (start_bottles)
      sprintf(*song++, template1,
              start_bottles,
              start_bottles == 1 ? "" : "s",
              start_bottles,
              start_bottles == 1 ? "" : "s");
    else
      sprintf(*song++, "%s", template1_0);

    start_bottles = start_bottles ? start_bottles - 1 : 99;

    if (start_bottles)
      sprintf(*song++, template2,
              start_bottles == 99 ? "Go to the store and buy some more" : "Take one down and pass it around",
              start_bottles,
              start_bottles == 1 ? "" : "s"
              );
    else
      sprintf(*song++, "%s", template2_0);
  }
}
