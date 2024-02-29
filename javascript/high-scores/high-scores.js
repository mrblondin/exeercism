export class HighScores {
  #scores
  constructor(scores) {
    this.#scores = scores;
  }

  get scores() {
    return this.#scores;
  }

  get latest() {
    return this.#scores.slice(-1)[0];
  }

  get personalBest() {
    return Math.max(...this.#scores);
  }

  get personalTopThree() {
    return [...this.#scores].sort((a, b) => b - a).slice(0, 3);
  }
}
