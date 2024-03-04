export const transpose = (input) => {
  const max_length = input.reduce((acc, curr) => 
    acc = curr.length > acc ? curr.length : acc  , 0);

  return input.reduce((acc, curr, index) => {
    curr.split('').map((l, i) => {
      while(acc[i].length < index) acc[i] += ' ';
      acc[i] += l;
    }); 
    return acc;
  }, Array(max_length).fill(''));
};
