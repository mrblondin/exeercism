export const spiralMatrix = (dim) => {
  const matrix = Array(dim).fill([]).map(_ => Array(dim));
  let counter = 1, border = 0;
  for (; border < dim / 2; ++border){
    let row = border, col = border, len = dim - 2 * border - 1;
    for (let progress = 0; progress < (4 * len ? 4 * len : 1); ++progress, ++counter){
      const side = progress / len;
      if (side === 0) {/* starting point / center */}
      else if (side <= 1) row++;
      else if (side <= 2) col++;
      else if (side <= 3) row--;
      else if (side <= 4) col--;
      matrix[col][row] = counter;
    }
  }
  return matrix;
};
