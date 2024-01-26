#include "space_age.h"

#define SECONDS_PER_YEAR_ON_EARTH (365.25 * 24 * 60 * 60)

struct Planet planets[] = {
  {MERCURY, 0.2408467},
  {VENUS, 0.61519726},
  {EARTH, 1.0},
  {MARS, 1.8808158},
  {JUPITER, 11.862615},
  {SATURN, 29.447498},
  {URANUS, 84.016846},
  {NEPTUNE, 164.79132}
};


float age(planet_t planet, int64_t seconds) {
  return (seconds / SECONDS_PER_YEAR_ON_EARTH / planets[planet].orbitalPeriod);
}
