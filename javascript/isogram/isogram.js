export const isIsogram = (word) => {
  const l_set = new Set();
  for (const l of [...word.toLowerCase().replace(/[^a-z]/g, '')]){
    if (l_set.has(l)) return false;
    else l_set.add(l);
  }
  return true;
};
