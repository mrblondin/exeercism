const WORKING_HOURS_PER_DAY = 8;
const MONTH_BILLABLE_DAYS = 22;
/**
 * The day rate, given a rate per hour
 *
 * @param {number} ratePerHour
 * @returns {number} the rate per day
 */
export const dayRate = ratePerHour =>
  ratePerHour * WORKING_HOURS_PER_DAY;

/**
 * Calculates the number of days in a budget, rounded down
 *
 * @param {number} budget: the total budget
 * @param {number} ratePerHour: the rate per hour
 * @returns {number} the number of days
 */
export const daysInBudget = (budget, ratePerHour) =>
  Math.floor(budget / dayRate(ratePerHour));

/**
 * Calculates the discounted rate for large projects, rounded up
 *
 * @param {number} ratePerHour
 * @param {number} numDays: number of days the project spans
 * @param {number} discount: for example 20% written as 0.2
 * @returns {number} the rounded up discounted rate
 */
export const priceWithMonthlyDiscount = (ratePerHour, numDays, discount) => {
  const discountedDays = Math.floor(numDays / MONTH_BILLABLE_DAYS) * MONTH_BILLABLE_DAYS;
  const remainderDays = numDays % MONTH_BILLABLE_DAYS;

  return Math.ceil(ratePerHour * WORKING_HOURS_PER_DAY *
    (discountedDays * (1 - discount) + remainderDays)
  )
}
