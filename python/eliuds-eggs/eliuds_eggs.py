def egg_count(display_value):
    sum = 0
    while display_value > 0:
        if display_value % 2:
            display_value -= 1
            sum += 1
        display_value /= 2

    return sum
