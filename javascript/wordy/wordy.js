const plus = (x, y) => x + y;
const minus = (x, y) => x - y;
const multiply = (x, y) => x * y;
const divide = (x, y) => x / y;

const OPERATIONS = { "plus": plus, "minus": minus, 
  "multiplied": multiply, "divided": divide};

export const answer = (question) => {
  let result = 0;

  let question_regex = /^What is(.*)\?$/g.exec(question)
  if (question_regex == null) throw new Error('Unknown operation')

  let q_arr = question.replace(/What is\s|\sby|\?/g, "").split(" ");

  result = Number(q_arr.shift());
  if (!result) throw new Error('Syntax error');

  while(q_arr.length > 0){
    let action = null;

    if (!isNaN(q_arr[0])) throw new Error('Syntax error');

    for (const[key, value] of Object.entries(OPERATIONS)){
      if (q_arr[0] === key){
        action = value;
        q_arr.shift();
      }
    }

    if (!action) throw new Error('Unknown operation');

    const val = Number(q_arr.shift());

    if (!val) throw new Error('Syntax error');
    
    result = action(result, val);
  }

  return result;
};
