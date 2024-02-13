export class Triangle {
    #sides
    #isReal
    constructor(...sides) {
      this.#sides = sides;
      const [a, b, c] = sides.sort((a, b) => a - b)
      this.#isReal = (a + b > c) && sides.length === 3
    }

    get isEquilateral() {
      const [a, b, c] = this.#sides
      return [a, b, c].every((v, i, a) => 
          (v === a[0] && v!== 0 && v != null)
      ) && this.#isReal
    }

    get isIsosceles() {
      const [a, b, c] = this.#sides
      return ((a == b || b == c || a == c)) && this.#isReal
    }

    get isScalene() {
      const [a, b, c] = this.#sides
      return (a != b && b != c && a != c) && this.#isReal
    }
}
