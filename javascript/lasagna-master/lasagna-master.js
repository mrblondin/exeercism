/// <reference path="./global.d.ts" />
// @ts-check

const MIN_PER_LAYER = 2;
const NOODLES_PER_LAYER = 50;
const SAUCE_PER_LAYER = 0.2;
const PORTIONS_PER_RECIPE = 2;

/**
 * Determines if lasagna is done
 *
 * @param {number} minutesLeftToCook
 * @returns {string} status of cooking
 */
export const cookingStatus = minutesLeftToCook => {
  if (isNaN(minutesLeftToCook))
    return 'You forgot to set the timer.';

  return minutesLeftToCook ? 
    'Not done, please wait.' : 'Lasagna is done.';
}


/**
 * Determines Lasagna preparation time
 *
 * @param {string[]} layers
 * @returns {number} minutes to prepare the dish
 */
export const preparationTime = (layers, minPerLayer = MIN_PER_LAYER) =>
  layers.length * minPerLayer;

/**
 * Determines the amounts of noodles and sauce needed
 *
 * @param {string[]} layers
 * @returns {Record<string, number>} object with amounts of needed ingridients
 */
export const quantities = layers =>
  ({ noodles: NOODLES_PER_LAYER * (layers.reduce((acc, curr) =>
      curr == 'noodles' ? ++acc: acc, 0)),
    sauce: SAUCE_PER_LAYER * (layers.reduce((acc, curr) =>
      curr == 'sauce' ? ++acc: acc, 0))});


/**
 * Add the last ingridient from friendList to myList
 *
 * @param {string[]} friendList of layers
 * @param {string[]} myList of layers
 * @returns {void}
 */
export const addSecretIngredient = (friendList, myList) => {
  myList.push(friendList.slice(-1)[0]);
}


/**
 * Scale the recipe. The standart recipe counts only for 
 * PORTIONS_PER_RECIPE
 *
 * @param {Record<string, number>} recipe
 * @param {number} portions
 * @returns {Record<string, number>} recipe, updated according
 *  requested amount of portions
 */
export const scaleRecipe = (recipe, portions) => 
  Object.fromEntries(Object.entries(recipe).map(([ingredient, amount]) => 
    [ingredient, amount * portions / PORTIONS_PER_RECIPE]))
