// it took 0.24 seconds to perform all the test

// quadratic equation: sum ** 2 - 2 * sum * (a + b) + 2 a * b = 0
// proceed backtracking for this equation
// b = (2 * sum * a - sum ** 2) / (2 * (a - sum))
export function triplets({ minFactor = 1, maxFactor = 0, sum }) {
  const arr = [];
  for (let a = minFactor; a < sum / 3; a++){
    const b = (2 * sum * a - sum ** 2) / (2 * (a - sum));
    if (b > a && b % 1 === 0 && (!maxFactor || (sum - a - b) < maxFactor))
      arr.push(new Triplet(a, b, sum - a - b));
    
    if (b <= a)
      break;
  }

  return arr;
}

class Triplet {
  constructor(a, b, c) {
    this.a = a; this.b = b; this.c = c;
  }

  toArray() {
    return [this.a, this.b, this.c];
  }
}
