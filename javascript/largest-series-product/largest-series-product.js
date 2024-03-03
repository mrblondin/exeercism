const is_valid_slice = (series, slice_length) => {
  if (series.match(/[^0-9]/gi)) throw new Error('Digits input must only contain digits')
  if (slice_length < 1) throw new Error('Span must be greater than zero');
  if (series.length < slice_length) 
    throw new Error('Span must be smaller than string length');
  return true;
}

export const largestProduct = (series, sliceLength) => {
  if (!is_valid_slice(series, sliceLength)) 
    return;
  return Math.max(...[...series].reduce((acc, _, index) => { 
    index + sliceLength <= series.length ? 
    acc.push(series.substring(index, index + sliceLength).split('').map(Number)
        .reduce((mul, curr) => curr * mul, 1)) : acc; 
    return acc;
  }, []));
};
