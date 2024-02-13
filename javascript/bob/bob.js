const isSilent = text => text.trim() === '';
const isQuestion = text => text.trim().slice(-1) === "?";
const isShouting = text => /[a-z]/i.test(text) && text.toUpperCase() === text;
const isShoutingQuestion = text => isQuestion(text) && isShouting(text);
const isDefault = () => true;

const rules = [
  {test: isSilent, response: "Fine. Be that way!"},
  {test: isShoutingQuestion, response: "Calm down, I know what I'm doing!"},
  {test: isShouting, response: "Whoa, chill out!"},
  {test: isQuestion, response: "Sure."},
  {test: isDefault, response: "Whatever."},
  
]

export const hey = (message) => {

  return rules.find(rule => rule.test(message)).response;

  // Possible only regex solution
  /*
  switch (true){
    case /^[A-Z\s]+\?$/.test(message):
      return "Calm down, I know what I'm doing!";
    case /^[a-zA-Z0-9,!-@#$%^&*()_+[\]{};:'",\s]*\?\s*$/.test(message):
      return "Sure.";
    case /^[A-Z0-9,!-@#$%^&*()_+[\]{};:'",\s]*[A-Z][A-Z0-9,!-@#$%^&*()_+[\]{};:'",\s]*!*$/.test(message):
      return "Whoa, chill out!";
    case /^\s*$/.test(message):
      return "Fine. Be that way!";
    default:
      return "Whatever.";
  }
  */
};
