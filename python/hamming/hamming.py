def distance(strand_a, strand_b):
    la, lb = len(strand_a), len(strand_b)
    if la != lb:
        raise ValueError("Strands must be of equal length.")

    return sum([1 for i in range(la) if strand_a[i] != strand_b[i]])
