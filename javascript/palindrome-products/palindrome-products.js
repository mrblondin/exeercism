// performing time 0.511 seconds
//
// look for smallest value, iterating from minFactor upwards,
// then for largest value, iterating from maxFactors downwards

const MIN = 0;
const MAX = 1;

export class Palindromes {
  static generate(factors) {
    if (factors.minFactor > factors.maxFactor)
      throw new Error('min must be <= max');

    const values = {smallest: { value: null, factors: []}, 
                     largest: { value: null, factors: []}};
    // Find smallest
    for (let i = factors.minFactor; i <= factors.maxFactor; i++) {
      if (i % 10 === 0) continue;
      if (values.smallest.value && (i * i) > values.smallest.value)
        break;
      for (let j = i; j <= factors.maxFactor; j++) {
        if (j % 10 === 0) continue;
        if (Palindromes.is_palindrome(i * j))
          values.smallest = Palindromes.update_values(values.smallest, i, j, MIN);
      }
    }

    // Find largest
    for (let i = factors.maxFactor; i >= factors.minFactor; i--) {
      if (i % 10 === 0) continue;
      if (values.largest.value && (i * i) < (values.largest.value))
        break;
      for (let j = i; j >= factors.minFactor; j--) {
        if (j % 10 === 0) continue;
        if (Palindromes.is_palindrome(i * j)){
          values.largest = Palindromes.update_values(values.largest, j, i, MAX);
        }
      }
    }
    return values;
  }

  static update_values(value, i, j, side){
    const val = i * j;
    if ((side === MIN && (!value.value || val < value.value))
         || ((side === MAX) && (!value.value || val > value.value)))
      value = { value: val, factors: [[i, j]] };
    else if (val === value.value)
      value.factors.push([i, j]);
    
    return value;
  } 

  static is_palindrome(number) {
    if (number % 10 === 0)
      return false;
    let reversed = 0;
    while (number > reversed){
      reversed = reversed * 10 + number % 10;
      number = Math.floor(number / 10);
    }

    return number === reversed || number === Math.floor(reversed / 10);
  }
}
