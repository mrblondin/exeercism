export class Scale {
  static sign_length = 12;
  static signs_sharp = ['A','A#','B','C','C#','D','D#','E','F','F#','G','G#'];
  static signs_flat  = ['A','Bb','B','C','Db','D','Eb','E','F','Gb','G','Ab'];
  static sharp_start = ['C','G','D','A','E','B','F#','e','b','f#','c#','g#','d#','a'];
  static flat_start  = ['F','Bb','Eb','Ab','Db','Gb','d','g','c','f','bb','eb'];
  static pause = "M";
  static augmented_pause = "A";
  #chromatic

  constructor(tonic) {
    let signs = '';
    if (Scale.sharp_start.includes(tonic)) signs = Scale.signs_sharp;
    else if (Scale.flat_start.includes(tonic)) signs = Scale.signs_flat;
    else throw new Error('Wrong tonic!');
    const index = signs.indexOf(tonic[0].toUpperCase() + tonic.slice(1));
    signs = [...signs.slice(index),...signs.slice(0, index)];
    this.#chromatic = signs;
  }

  chromatic = _ => this.#chromatic;

  interval(intervals) {
    let i = 0; const output = [];
    for (const interval of [...intervals, '']){
      output.push(this.#chromatic[i % 12]); 
      i = i + (interval === Scale.augmented_pause ? 3 
            : (interval === Scale.pause ? 2 : 1));
    }
    return output;
  }
}
