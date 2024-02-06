def reverse(text):
    reversed = []
    for char in text:
        reversed = [char, *reversed]
    return ''.join(reversed)
