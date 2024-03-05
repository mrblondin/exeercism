// x and y coordinates are swapped for point coordinates [y,x] because 
// y iterated first in arrays. Even thoug x is horizontal coordinate
const H_LINE = '-';
const V_LINE = '|';
const PLUS = '+';

const is_v_line = (diagram, p1, p2) => {
  for (let z = p1[0] + 1; z < p2[0]; z++){ 
    if (diagram[z][p1[1]] !== PLUS && diagram[z][p1[1]] !== V_LINE)
      return false;
  }
  return true;
}

const is_h_line = (diagram, p1, p2) => {
  for (let z = p1[1] + 1; z < p2[1]; z++){
    if (diagram[p1[0]][z] !== PLUS && diagram[p1[0]][z] !== H_LINE)
      return false;
  }
  return true;
}

export function count(input) {
  let count = 0;
  const diagram = input.map(v => v.split(''));
  const y_length = diagram.length;
  for (let i = 0; i < y_length - 1; i++) {
    for (let j = 0; j < diagram[i].length - 1; j++){
      if (diagram[i][j] !== PLUS)
        continue;
      // found 1st corner
      for (let x = j + 1; x < diagram[i].length; x++){
        if (diagram[i][x] !== H_LINE && diagram[i][x] !== PLUS) break;
        if (diagram[i][x] !== PLUS) continue;
        // found 2nd corner
        for (let y = i + 1; y < y_length; y++){
          if (diagram[y][j] !== V_LINE && diagram[y][j] !== PLUS) break
          if (diagram[y][j] !== PLUS || diagram[y][x] !== PLUS) continue;
            // found 3rd corner and 4th corner, check the paths to 4th corner                
            if (is_v_line(diagram, [i, x], [y, x]) && 
              is_h_line(diagram, [y, j], [y, x]))
              count++;
        }
      }
    }
  }
  return count;
}
