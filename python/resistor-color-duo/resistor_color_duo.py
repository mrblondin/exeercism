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


def value(colors):
    col1, col2 = colors[:2]
    return COLORS[col1] * 10 + COLORS[col2]
