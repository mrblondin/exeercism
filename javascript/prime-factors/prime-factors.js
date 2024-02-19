export const primeFactors = (number) => {
  const factors = [];
  for (let i = 2; number > 1; i++){
    while (number % i === 0) {
      number /= i;
      factors.push(i);
    }
  }

  return factors;
};
