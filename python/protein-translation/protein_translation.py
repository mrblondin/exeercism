def proteins(strand):
    name_map = {
        7: 'Methionine', 1: 'Phenylalanine', 2: 'Leucine', 3: 'Serine',
        4: 'Tyrosine', 5: 'Cysteine', 6: 'Tryptophan'
    }
    protein_map = {
        'AUG': 7, 'UUU': 1, 'UUC': 1, 'UUA': 2, 'UUG': 2, 'UCU': 3, 'UCC': 3,
        'UCA': 3, 'UCG': 3, 'UAU': 4, 'UAC': 4, 'UGU': 5, 'UGC': 5, 'UGG': 6,
        'UAA': 0, 'UAG': 0, 'UGA': 0
    }

    output = []
    for i in range(0, len(strand), 3):
        code = strand[i:i + 3]
        if not protein_map[code]:
            break
        output.append(name_map[protein_map[code]])

    return output
