const VALUES_LETTERS = {
  1: "AEIOULNRST",
  2: "DG",
  3: "BCMP",
  4: "FHVWY",
  5: "K",
  8: "JX",
  10: "QZ"
}

export const score = (words) => {
  // translate value-letter to letter-value
  const letter_values = {};
  Object.entries(VALUES_LETTERS).forEach(([key, value]) => 
    [...value].forEach((val) => letter_values[val] = Number(key))
  );

  return [...words.toUpperCase()].reduce((acc, curr) => 
    acc + letter_values[curr], 0);
};
