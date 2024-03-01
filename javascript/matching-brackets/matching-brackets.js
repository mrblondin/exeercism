export const isPaired = (input) => {
  const MAP_BRACKETS = {'}': '{', ']': '[', ')': '('}; 
  const OPENING = "{[(";
  const stack = [];

  for (const s of input){
    if (OPENING.includes(s)) stack.push(s); 
    else if (!!MAP_BRACKETS[s] && stack && stack.pop() !== MAP_BRACKETS[s])
        return false;
  }
  return stack.length === 0;
};
