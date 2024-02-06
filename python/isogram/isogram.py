import re


def is_isogram(string):
    scrubbed = re.compile('[^a-zA-Z]').sub('', string).lower()
    return len(set(scrubbed)) == len(scrubbed)
