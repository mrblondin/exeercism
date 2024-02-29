export const parse = (phrase) => {
  return phrase.match(/[\w']+|[\w]+(?:-[\w]+)/g)
               .map(w => w.replace('_','')[0].toUpperCase()).join('');
};
