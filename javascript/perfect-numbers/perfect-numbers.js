export const classify = (number) => {
  if (number < 1)
    throw new Error('Classification is only possible for natural numbers.');

  let res = 0;
  for (let i = 1; i <= number / 2; i++)
    res = !(number % i) ? res + i : res;

  if (res > number) return 'abundant';
  if (res < number) return 'deficient';
  return 'perfect';
};
