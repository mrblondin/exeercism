/**
 * Find anagrams to target among candidates
 * @param {string} target
 * @param {Array[string]} candidates
 * return {Array[string]}
 */
export const findAnagrams = (target, candidates) => {
  const t_lower = target.toLowerCase();
  const t_sorted = [...target.toLowerCase()].sort().join('');
  return candidates.filter(c => t_lower !== c.toLowerCase() &&
    [...c.toLowerCase()].sort().join('') === t_sorted);

  // Check sum variant, it is not proper method
  //const t_sum = [...target.toLowerCase()]
  //                    .reduce((acc, curr) => acc + curr.charCodeAt(0), 0);
  //
  //return candidates.filter(c => [...c.toLowerCase()].reduce((acc, curr) => 
  //                         acc + curr.charCodeAt(0), 0) === t_sum 
  //                         && c.toLowerCase() != target.toLowerCase());
};
