/// <reference path="./global.d.ts" />
// @ts-check

const PRICES = {
  'Margherita': 7,
  'Caprese': 9,
  'Formaggio': 10,
  'ExtraSauce': 1,
  'ExtraToppings': 2
}

/**
 * Determine the prize of the pizza given the pizza and optional extras
 *
 * @param {Pizza} pizza name of the pizza to be made
 * @param {Extra[]} extras list of extras
 *
 * @returns {number} the price of the pizza
 */
export const pizzaPrice = (pizza, ...extras) =>
  extras.length > 0 ? PRICES[extras.pop()] + pizzaPrice(pizza, ...extras) : PRICES[pizza];

/**
 * Calculate the prize of the total order, given individual orders
 *
 * @param {PizzaOrder[]} pizzaOrders a list of pizza orders
 * @returns {number} the price of the total order
 */
export const orderPrice = pizzaOrders => {

  // solution with recursive function
  //const order = pizzaOrders.pop();
  //return order ? pizzaPrice(order.pizza, ...order.extras) + orderPrice(pizzaOrders) : 0;

  // solution with loop
  return pizzaOrders.reduce((acc, curr) => {
    return acc + pizzaPrice(curr.pizza, ...curr.extras);
  }, 0)
}
