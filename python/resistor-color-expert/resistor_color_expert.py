COLORS = {"black":  0, "brown":  1, "red":    2, "orange": 3, "yellow": 4,
          "green":  5, "blue":   6, "violet": 7, "grey":   8, "white":  9}
ZEROS = {9: "giga", 6: "mega", 3: "kilo", 0: ""}
TOLERANCE = {"grey": 0.05, "violet": 0.1, "blue": 0.25, "green": 0.5,
             "brown": 1, "red": 2, "gold": 5, "silver": 10}


def resistor_label(col):
    if len(col) == 1:
        return "0 ohms"

    value, tolerance = ((COLORS[col[0]] * 100 + COLORS[col[1]] * 10 +
                        COLORS[col[2]]) * (10 ** COLORS[col[3]]),
                        TOLERANCE[col[4]]) if len(col) == 5 \
        else ((COLORS[col[0]] * 10 + COLORS[col[1]]) *
              (10 ** COLORS[col[2]]), TOLERANCE[col[3]])

    (divider, prefix) = next((item for item in ZEROS.items()
                             if value / (10 ** item[0]) > 1))

    return f'{value / (10 ** divider):g} {prefix}ohms ±{tolerance}%'
