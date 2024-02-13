const PRICE = 800;
const DISCOUNTS = { 
  1: 1,
  2: 0.95, 
  3: 0.9, 
  4: 0.8, 
  5: 0.75
};

/**
 * My solution in this task:
 *
 * 1. Find maximum possible baskets with only one group or only one type of discount
 * i.e. [1, 1, 2, 3, 4, 4, 5, 5]
 * max 5 items discount: 1 [5]
 * max 4 items discount: 2 [4, 4]
 * max 3 items discount: 2 [3, 3]
 * max 2 items discount: 4 [2, 2, 2, 2]
 * max 1 items discount: 8 [1, 1, ...] (discount 0%)
 *
 * 2. Create array from max's of each discount type
 * variants = [ 5, 4, 4, 3, 3, 2, .....]
 *
 * 3. Go through this array, every time starting from next element. Get price for each
 * starting position
 * variant1 = [ 5, 4, 4, 3, 3, 2, .....]
 * variant2 = [ 4, 4, 3, 3, 2, .....]
 * variant3 = [ 4, 3, 3, 2, .....]
 *
 * 4. Choose the best price
 */

export const cost = (books) => {
  let books_array = [];
  const variants = [];
  for (let type of new Set(books)){
    books_array.push(books.reduce((acc, curr) => 
      acc + (curr === type ? 1:0), 0));
  }

  // sorting is needed to get rid off the elements that are presented more
  books_array = books_array.sort((a, b) => b - a);

  // group is discount group, 5,4,3,2,1
  for (let group = books_array.length; group > 0; group--) {
    let arr = [...books_array]; //copy of books_array

    while (group <= arr.length) {
      variants.push(group);
      arr = arr.map((value, index) => index < group ? (value - 1) : value)
        .filter(value => value > 0);
    }
  }

  // initPrice
  let price = books.length * PRICE;

  // iterate variants
  for (let start = 0; start < variants.length - books.length; start++) {
    let temp_price = 0;
    let arr = [...books_array];
    const variant = variants.slice(start); 

    // calculate the price
    for (let group of variant){
      if (group <= arr.length){
        temp_price += PRICE*DISCOUNTS[group]*group;
        arr = arr.map((value, index) => index < group ? (value - 1) : value)
          .filter(value => value > 0);
      }
    }

    if (arr.length === 0)
      price = Math.min(price, temp_price);// temp_price < price ? temp_price : price;
  }

  return price;
};
