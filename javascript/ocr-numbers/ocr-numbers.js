const ROWS_PER_NUM = 4;
const COLS_PER_NUM = 3;

const NUM = {
  0: [' _ ','| |','|_|','   '],
  1: ['   ','  |','  |','   '],
  2: [' _ ',' _|','|_ ','   '],
  3: [' _ ',' _|',' _|','   '],
  4: ['   ','|_|','  |','   '],
  5: [' _ ','|_ ',' _|','   '],
  6: [' _ ','|_ ','|_|','   '],
  7: [' _ ','  |','  |','   '],
  8: [' _ ','|_|','|_|','   '],
  9: [' _ ','|_|',' _|','   '],
}

export const convert = input => input.split('\n').reduce((acc, curr, index) => {
    const ri = Math.floor(index / ROWS_PER_NUM);
    curr.match(new RegExp(`.{1,${COLS_PER_NUM}}`, 'g')).forEach((v, i) => {
      acc?.[ri] ? (acc[ri]?.[i] ? acc[ri][i].push(v) 
                                : acc[ri].push([v])) 
                : acc.push([[v]]); 
    });
    return acc;
  }, []).map(v => v.map(n => 
      Object.keys(NUM).find(k => 
        NUM[k].toString() === n.toString()) || '?').join('')).join(',');
