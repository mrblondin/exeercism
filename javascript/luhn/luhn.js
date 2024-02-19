export const valid = number => {
  if (!/^[0-9\s]+$/.test(number) || number.trim() === '0')
    return false;

  return [...number.replace(/[^0-9]/g, "")]
    .reverse()
    .map((val, index) => 
      !(index % 2) ? Number(val) : (val * 2 > 9 ? val * 2 - 9 : val * 2))
    .reduce((acc, curr) => acc + curr, 0) % 10 === 0;
};
