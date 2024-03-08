export const saddlePoints = (input) => {
  const col_min = {}; const col_coord = {};
  const row_max = {}; const row_coord = {};
  for (let r = 0; r < input.length; r++) {
    row_max[r] = 0;
    for (let c = 0; c < input[r].length; c++){
      if (!col_min[c]) col_min[c] = Infinity;
      if (col_min[c] > input[r][c]){
        col_min[c] = input[r][c]; col_coord[c] = [r];
      }
      else if (col_min[c] === input[r][c]) col_coord[c].push(r);
      if (row_max[r] < input[r][c]) {
        row_max[r] = input[r][c]; row_coord[r] = [c]
      }
      else if (row_max[r] === input[r][c]) row_coord[r].push(c);
    }
  }

  return Object.entries(row_coord).reduce((acc, [key, value]) => { 
    key = Number(key);
    value.forEach(v => { 
      if (col_coord[v].includes(key)) acc.push({row: key + 1, column: v + 1});
    });
    return acc;
  }, []);
};
