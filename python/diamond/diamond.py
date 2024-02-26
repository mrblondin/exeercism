def rows(letter):
    a, letter = ord('A'), ord(letter)
    diff = letter - a
    output = []

    for i in range(2*diff + 1):
        position = i if i <= diff else (2*diff - i)
        output.append(''.join([' ' if abs(j) != position else chr(a + position)
                               for j in range(-diff, diff + 1)]))
    return output
