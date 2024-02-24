VOWELS = ['a', 'e', 'i', 'o', 'u', 'y']
SUF = 'ay'


def translate(text):
    return ' '.join([translate_word(word) for word in text.split()])


def translate_word(word):
    vowel_set = set(VOWELS)
    vowel_index = 0
    length = len(word)

    if word.startswith('xr') or word.startswith('yt'):
        return word + SUF

    for i in range(length):
        if (word[i] in vowel_set and
                not (i > 0 and word[i] == 'u' and word[i-1] == 'q') and
                not (i == 0 and word[i] == 'y')):
            vowel_index = i
            break

    return word[vowel_index:] + word[:vowel_index] + SUF
