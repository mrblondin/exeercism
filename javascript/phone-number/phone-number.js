const MAX_NUMBER = 11;
const LENGTH = 10;
const AREA_INDEX = 0;
const EXCHANGE_INDEX = 3;

export const clean = input => {
    let output = '';
    if (/[\:$%\^@!]/.test(input)) throw new Error('Punctuations not permitted');
    if (/[a-z]/i.test(input)) throw new Error("Letters not permitted"); 
    for (const [index, value] of [...input.replace(/^1|^\+1|[()-\s\.]/g,'')].entries()){
        const digit = parseInt(value);
        if ((index == AREA_INDEX || index == EXCHANGE_INDEX) && digit < 2) 
          throw new Error(`${index == AREA_INDEX ? 'Area': 'Exchange'} code cannot \
start with ${digit == AREA_INDEX ? 'zero' : 'one'}`);
        output += digit;
      }
    if (output.length === MAX_NUMBER) throw new Error(`${MAX_NUMBER} digits must start with 1`);
    if (output.length > MAX_NUMBER) throw new Error(`More than ${MAX_NUMBER} digits`);
    if (output.length !== LENGTH) throw new Error('Incorrect number of digits');

    return output;
}
