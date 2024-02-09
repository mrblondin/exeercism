COLORS = {
    "black":  0,
    "brown":  1,
    "red":    2,
    "orange": 3,
    "yellow": 4,
    "green":  5,
    "blue":   6,
    "violet": 7,
    "grey":   8,
    "white":  9
}

ZEROS = {
    9: "giga",
    6: "mega",
    3: "kilo"
}


def label(col):
    result = (COLORS[col[0]] * 10 + COLORS[col[1]]) * (10 ** COLORS[col[2]])
    resist = ''
    for key, value in ZEROS.items():
        if not result:
            break

        if result % (10 ** key) == 0:
            resist = value
            result //= (10 ** key)
            break

    return f'{result} {resist}ohms'
