// found here: https://learnersbucket.com/examples/algorithms/difference-between-square-of-sum-of-numbers-and-sum-of-square-of-numbers/#google_vignette

export class Squares {
  #num
  constructor(number) {
    this.#num = number;
  }

  get sumOfSquares() {
    return (this.#num * (this.#num + 1) * ((this.#num * 2) + 1)) / 6
  }

  get squareOfSum() {
    return ((this.#num * (this.#num + 1)) / 2) ** 2;
  }

  get difference() {
    return this.squareOfSum - this.sumOfSquares;
  }
}
