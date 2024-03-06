export const spiralMatrix = (n) => {
  const matrix = Array(n).fill([]).map(_ => Array(n));
  let i = 1, b = 0; // b = border thickness
  for (; b < n / 2; b++){
    let x = b, y = b, l = n - 2 * b;
    for (let j = 0; j < (4 * (l - 1) ? 4 * (l - 1) : 1); j++, i++){
      const adj = j / (l-1);
      if (adj === 0) {/* pass */}
      else if (adj <= 1) x++;
      else if (adj <= 2) y++;
      else if (adj <= 3) x--;
      else if (adj <= 4) y--;
      matrix[y][x] = i;
    }
  }
  return matrix;
};
