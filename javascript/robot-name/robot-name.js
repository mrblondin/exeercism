// the whole bunch of tests performed in 15 seconds.

const TOTAL_NUMBER_OF_NAMES = 26 * 26 * 10 * 10 * 10;

export class Robot {
  static names = new Set();

  constructor() {
    this._name = this.#generate_name();
  }
  
  get name() { return this._name; }

  reset = () => this._name = this.#generate_name();

  static to_char = num => String.fromCharCode(num + 65);

  #generate_name = () => {
    let code = null;
    let letter_code = [];
    let digit_code = [];
    let number_code = (0|Math.random() * TOTAL_NUMBER_OF_NAMES);

    while (!code){
      if (Robot.names.has(number_code) == true){
        number_code = (number_code + 1) % TOTAL_NUMBER_OF_NAMES;
        continue;
      }

      letter_code[0] = Math.floor(number_code / 26 / 10 / 10 / 10);
      letter_code[1] = Math.floor(number_code / 10 / 10 / 10) % 26;
      digit_code[0]  = Math.floor(number_code / 10 / 10) % 10;
      digit_code[1]  = Math.floor(number_code / 10) % 10;
      digit_code[2]  = number_code % 10;

      code = letter_code.map(Robot.to_char).join('') + digit_code.join('');
      break;
    }
    Robot.names.add(number_code);
    return code;
  }
}

Robot.releaseNames = () => {
  Robot.names = new Set();
};
