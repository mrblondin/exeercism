//@ts-check

const YEAR_PLANET_CONVERSION = {
  'mercury': 0.2408467,
  'venus': 0.61519726,
  'mars': 1.8808158,
  'earth': 1,
  'jupiter': 11.862615,
  'saturn': 29.447498,
  'uranus': 84.016846,
  'neptune': 164.79132
};

const SECONDS_IN_YEAR_ON_EARTH = 31557600;

/**
 * Return age in years on different planets
 * @param {string} planet name
 * @param {number} timeSec, Earth age in seconds
 * return {number} age in years
 */
export const age = (planet, timeSec) => 
  Number((timeSec / SECONDS_IN_YEAR_ON_EARTH 
    / YEAR_PLANET_CONVERSION[planet]).toFixed(2))
