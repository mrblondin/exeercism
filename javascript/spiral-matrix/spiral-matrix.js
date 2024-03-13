export const spiralMatrix = (dim) => {
  const matrix = Array(dim).fill([]).map(_ => Array(dim));
  for (let counter = 1, depth = 0; depth < dim / 2; ++depth){
    let row = depth, col = depth, side = dim - 2 * depth - 1;
    for (let progress = 0; progress < (4 * side || 1); ++progress, ++counter){
      switch(Math.ceil(progress / side)){
        case 0: break; /* starting point / center -- don't move yet */
        case 1: ++row; break;
        case 2: ++col; break;
        case 3: --row; break;
        case 4: --col; break;
      }
      matrix[col][row] = counter;
    }
  }
  return matrix;
};
