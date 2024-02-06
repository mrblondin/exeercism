export const commands = (code) => {
  const codes = { 0b1: "wink", 0b10: "double blink", 0b100: "close your eyes",
                  0b1000: "jump"};
  const reverse = 0b10000;

  let result = [];

  for (const [key, value] of Object.entries(codes))
    if (key & code) result.push(value);

  return ((reverse & code) ? result.reverse() : result)
};
