def is_pangram(sentence):
    return set("abcdefghijklmnopqrstuvwqxyz") <= set(sentence.lower())
