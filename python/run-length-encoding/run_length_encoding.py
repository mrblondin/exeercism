ASCII_0 = 48
ASCII_9 = 57


def decode(string):
    output = ''
    count = 0
    for symbol in string:
        if ord(symbol) >= ASCII_0 and ord(symbol) <= ASCII_9:
            count = 10 * count + int(symbol)
        else:
            output += symbol * count if count else symbol
            count = 0
    return output


def encode(string):
    output, prev, count = '', '', 0
    string += '.'
    for symbol in string:
        if prev == symbol:
            count += 1
        else:
            output += (f'{count}{prev}' if count > 1 else prev) if count else ''
            prev, count = symbol, 1
    return output
