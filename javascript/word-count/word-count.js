export const countWords = (string) => {
  return string.toLowerCase().match(/\w+('\w+)?/g).reduce((acc, curr) => {
    curr in acc ? acc[curr]++ : acc[curr] = 1;
    return acc;
  }, {});
};
