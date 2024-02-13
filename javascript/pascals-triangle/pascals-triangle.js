/**
 * Build pascal triangle depending on row number
 * @param {number} rows
 * return {number[]} double array with values of pascals Triangle
 */
export const rows = (rows) => {

  const trianlge = [];

  for (let row = 0; row < rows; row++){
    // first row is filled in manually
    if (!row) {
      trianlge[row] = [1]; 
      continue;
    }
    
    trianlge[row] = []
    const prev_row = trianlge[row-1];
    const cur_row = trianlge[row];

    for (let column = 0; column < prev_row.length + 1; column++){
      const prev_col1 = prev_row[column - 1] ?
        prev_row[column - 1] : 0;
      const prev_col2 = prev_row[column] ? 
        prev_row[column] : 0;

      cur_row.push(prev_col1 + prev_col2);
    }
  }

  return trianlge;
};
