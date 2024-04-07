NUMBERS = {0: 'no', 1: 'one', 2: 'two', 3: 'three', 4: 'four', 5: 'five',
           6: 'six', 7: 'seven', 8: 'eight', 9: 'nine', 10: 'ten'}


def recite(start, take=1):
    output = []
    for count in range(start, start - take, -1):
        if output:
            output.append('')
        output += [(how_many_bottles(count) + " hanging on the wall,")
                   .capitalize()] * 2
        output += ["And if one green bottle should accidentally fall,"]
        output += [f"There'll be {how_many_bottles(count - 1)} \
hanging on the wall."]

    return output


def how_many_bottles(count):
    return f"{NUMBERS[count]} green bottle{'' if count == 1 else 's'}"
