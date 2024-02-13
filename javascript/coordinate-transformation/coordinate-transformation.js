// @ts-check

/**
 * Create a const that returns a function making use of a closure to
 * perform a repeatable 2d translation of a coordinate pair.
 *
 * @param {number} dx the translate x component
 * @param {number} dy the translate y component
 *
 * @returns {function} a function which takes an x, y parameter, returns the
 *  translated coordinate pair in the form [x, y]
 */
export const translate2d = (dx, dy) => {
  const translate = (x, y) => [x + dx, y + dy];
  return translate;
}


/**
 * Create a const that returns a function making use of a closure to
 * perform a repeatable 2d scale of a coordinate pair.
 *
 * @param {number} sx the amount to scale the x component
 * @param {number} sy the amount to scale the y component
 *
 * @returns {function} a function which takes an x, y parameter, returns the
 *  scaled coordinate pair in the form [x, y]
 */
export const scale2d = (sx, sy) => {
  const scale = (x, y) => [sx*x, y*sy];
  return scale;
}

/**
 * Create a composition const that returns a function that combines two
 * consts to perform a repeatable transformation
 *
 * @param {function} f the first function to apply
 * @param {function} g the second function to apply
 *
 * @returns {function} a function which takes an x, y parameter, returns the
 *  transformed coordinate pair in the form [x, y]
 */
export const composeTransform = (f, g) => (x, y) => g(...f(x, y));

/**
 * Return a const that memoizes the last result.  If the arguments are the same as the last call,
 * then memoized result returned.
 *
 * @param {function} f the transformation function to memoize, assumes takes two arguments 'x' and 'y'
 *
 * @returns {function} a function which takes x and y arguments, and will either return the saved result
 *  if the arguments are the same on subsequent calls, or compute a new result if they are different.
 */
export const memoizeTransform = (f) => {
  let n1, n2, res;
  const memorize = (x, y) => {
    if (x !== n1 && y !== n2)
      [n1, n2, res] = [x, y, f(x, y)];
    return res;
  }

  return memorize;
}
