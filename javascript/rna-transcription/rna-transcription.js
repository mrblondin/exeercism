const DNA_TO_RNA_TRANSLATION = {
  'G': 'C',
  'C': 'G',
  'T': 'A',
  'A': 'U'
}

export const toRna = (dna) =>
  dna ? [...dna].map((letter) => 
    DNA_TO_RNA_TRANSLATION[letter]).join('') : "";
