export class Clock {
  constructor(hour = 0, min = 0) {
    this.hour = hour;
    this.min = min;
    this.#normalize();
  }

  // @param {number} time, min or hour
  // returns {string}, formated time val "0x"
  static format = time => time.toString().padStart(2, '0');

  static modulo = (num, mod) => ((num % mod) + mod) % mod;

  #normalize = () => {
    this.hour = Clock.modulo(Math.floor((this.hour * 60 + this.min) / 60), 24);
    this.min = Clock.modulo(this.min, 60);
  }

  toString = () => `${Clock.format(this.hour)}:${Clock.format(this.min)}`;

  plus = min_add => { this.min += min_add; this.#normalize(); return this; }

  minus = min_sub => { this.min -= min_sub; this.#normalize(); return this; }

  equals = (some_clock) => this.toString() == some_clock.toString()
}
