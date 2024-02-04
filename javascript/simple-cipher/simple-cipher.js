const SMALL_LETTER_SHIFT = 97;
const NUM_LETTERS = 26;
const RANDOM_KEY_LENGTH = 100;

const DIRECTION = {
  ENCODE: 1,
  DECODE: -1
}


export class Cipher {
  constructor(key = this.#generate_key(RANDOM_KEY_LENGTH)) {
    if (!/^[a-z]+$/.test(key)) throw new Error('Bad key')
    this._key = key;
    this._key_length = this._key.length;
  }

  encode(text) {
    return this.#to_code(text, DIRECTION.ENCODE);
  }

  decode(code) {
    return this.#to_code(code, DIRECTION.DECODE);
  }

  get key() {
    return this._key;
  }

  // @param {number} direction - 1 for encode and -1 for decode
  #to_code(code, direction){
    return [...code].map((val, index) =>
      Cipher.index_to_letter(
        Cipher.shift_char_code(val, this._key[index % this._key_length], direction)
      )).join('');
  }

  #generate_key(length) {
    return Array.from({length}, Cipher.random_letter).join('');
  }

  static random_letter = () => Cipher.index_to_letter(0|Math.random() * NUM_LETTERS);

  static letter_to_index = (letter) => letter.charCodeAt(0) - SMALL_LETTER_SHIFT;

  static index_to_letter = (index) => 
    String.fromCharCode(index + SMALL_LETTER_SHIFT);

  static shift_char_code = (char_code, shift_code, direction) =>
    (Cipher.letter_to_index(char_code) + direction * Cipher.letter_to_index(shift_code) + 
      NUM_LETTERS) % NUM_LETTERS
}
