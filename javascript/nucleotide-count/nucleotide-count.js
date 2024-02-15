const NUCLEOS = 'ACGT';

export function countNucleotides(strand) {
  if (/[^ACGT]/.test(strand)) throw new Error('Invalid nucleotide in strand');
  const map = [...strand].reduce((acc, cur) => {
    acc[cur] = (cur in acc) ? acc[cur] + 1 : 1;
    return acc;
  }, {});

  return [...NUCLEOS].reduce((acc, cur) => { acc.push(cur in map ? map[cur] : 0); return acc }, []).join(' ');
}
