NUMS = {
    1: 'one', 2: 'two', 3: 'three', 4: 'four', 5: 'five', 6: 'six', 7: 'seven',
    8: 'eight', 9: 'nine', 10: 'ten', 11: 'eleven', 12: 'twelve',
    13: 'thirteen', 14: 'fourteen', 15: 'fifteen', 16: 'sixteen',
    17: 'seventeen', 18: 'eightteen', 19: 'nineteen', 20: 'twenty',
    30: 'thirty', 40: 'forty', 50: 'fifty', 60: 'sixty', 70: 'seventy',
    80: 'eighty', 90: 'ninety', 100: 'hundred', 1e3: 'thousand',
    1e6: 'million', 1e9: 'billion'
}

ZERO = 'zero'

MAX_RANGE = 1e12


def say(number):
    if number < 0 or number >= MAX_RANGE:
        raise ValueError("input out of range")

    output = ''
    for num_val, num_say in sorted(NUMS.items(), reverse=True):
        units, number = divmod(number, num_val)

        if units:
            prefix = say(units) + ' ' if num_val >= 100 else ''
            output += f"{prefix}{num_say}{' -'[10 < num_val < 100]}"

    return output[:-1] or ZERO
