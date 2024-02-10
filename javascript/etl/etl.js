export const transform = (values) => {
  return Object.entries(values).reduce((output, [key, vals]) => { 
    vals.forEach(letter => output[letter.toLowerCase()] = +key); return output}, 
    {});

/** Initial solution
  const converted = {};
  for (const [key, value] of Object.entries(values))
    for (const char of value)
      converted[char.toLowerCase()] = Number(key);

  return converted;
*/
};
