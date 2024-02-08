DNA_TO_RNA = {"G": "C", "C": "G", "T": "A", "A": "U"}


def to_rna(dna_strand):
    return ''.join([DNA_TO_RNA[nucleo] for nucleo in [*dna_strand]])
