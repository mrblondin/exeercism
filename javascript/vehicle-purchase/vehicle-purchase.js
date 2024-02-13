// @ts-check

const BETTER_CHOICE_STR = " is clearly the better choice.";

/**
 * Determines whether or not you need a license to operate a certain kind of vehicle.
 *
 * @param {string} kind
 * @returns {boolean} whether a license is required
 */
export const needsLicense = kind => kind === 'car' || kind === 'truck';

/**
 * Helps choosing between two options by recommending the one that
 * comes first in dictionary order.
 *
 * @param {string} option1
 * @param {string} option2
 * @returns {string} a sentence of advice which option to choose
 */
export const chooseVehicle = 
  (option1, option2) => (option1 < option2 ? option1 : option2) + 
    BETTER_CHOICE_STR;

/**
 * Calculates an estimate for the price of a used vehicle in the dealership
 * based on the original price and the age of the vehicle.
 *
 * @param {number} originalPrice
 * @param {number} age
 * @returns {number} expected resell price in the dealership
 */
export const calculateResellPrice = (originalPrice, age) => {
  let amortisation;
  if (age < 3)
    amortisation = 0.8;
  else if (age <= 10)
    amortisation = 0.7;
  else 
    amortisation = 0.5;

  return originalPrice * amortisation;
}
