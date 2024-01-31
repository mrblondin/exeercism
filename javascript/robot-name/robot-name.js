const DIGIT_NUM = 3;
const LETTER_NUM = 2;
const NUM = 5;
const LETTERS_AMOUNT = 26;
const DIGITS_AMOUNT = 10;
const TOTAL_NUMBER_OF_NAMES = 26 * 26 * 10 * 10 * 10;

export class Robot {
  static names = new Set();

  constructor() {
    this._name = this.#generate_name();
  }
  
  get name() { return this._name; }

  reset = () => this._name = this.#generate_name();

  static randomLetter = _ => String.fromCharCode(0|Math.random() * 26 + 65);
  static randomDigit = _ => 0|Math.random() * 9;

  #generate_name = () => {
    let code = null;
    while (!code){
      const letter_code = Array(LETTER_NUM).fill().map(Robot.randomLetter).join('');
      const digit_code = Array(DIGIT_NUM).fill().map(Robot.randomDigit).join('');
      code = letter_code + digit_code;
      code = Robot.names.has(code) ? null : code;
      //if (code = Robot.names.has(code) != true)
      //  break;

      // code exists, change each sign one by one
      //for (let i = 0; i < NUM; i++){
      //  for (let j = 0; j < (i < 2 ) ? LETTERS_AMOUNT : DIGITS_AMOUNT; j++)
      //  while (!code){
      //    code[i] 
      //  }
      //}
    }
    Robot.names.add(code);
    return code;
  }
}

Robot.releaseNames = () => {
  Robot.names = new Set();
};
