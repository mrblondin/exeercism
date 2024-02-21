def find_anagrams(word, candidates):
    output = []
    word_lower = word.lower()

    for candidate in candidates:
        letters = list(word_lower)
        can_lower = candidate.lower()
        if len(letters) != len(candidate) or word_lower == can_lower:
            continue
        for i in range(len(can_lower)):
            if can_lower[i] in letters:
                letters[letters.index(can_lower[i])] = ''
        if ''.join(letters) == '':
            output.append(candidate)
    return output
