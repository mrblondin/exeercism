export const compute = (dna1, dna2) => {
  if (dna1.length !== dna2.length) 
    throw new Error('strands must be of equal length')

  //let distance = 0;
  //[...dna1].forEach((letter, index) => { distance += (letter === dna2[index] ?
  //                                                    0 : 1)});

  return [...dna1].reduce((distance, letter, index) => 
    distance + (letter === dna2[index] ? 0 : 1), 0);
};
