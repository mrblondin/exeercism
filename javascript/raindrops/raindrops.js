const LOOKUP = {
  3: "Pling",
  5: "Plang",
  7: "Plong"
}

export const convert = (number) =>
  Object.entries(LOOKUP).reduce((noise, [factor, sound]) => 
    noise + (number % factor ? '': sound), '') || number.toString();
