NUMS = {
    1: 'one', 2: 'two', 3: 'three', 4: 'four', 5: 'five', 6: 'six', 7: 'seven',
    8: 'eight', 9: 'nine', 10: 'ten', 11: 'eleven', 12: 'twelve',
    13: 'thirteen', 14: 'fourteen', 15: 'fifteen', 16: 'sixteen',
    17: 'seventeen', 18: 'eightteen', 19: 'nineteen', 20: 'twenty-',
    30: 'thirty-', 40: 'forty-', 50: 'fifty-', 60: 'sixty-', 70: 'seventy-',
    80: 'eighty-', 90: 'ninety-', 100: 'hundred'
}

THOUSANDS = {
    1: '', 1e3: 'thousand', 1e6: 'million', 1e9: 'billion'
}

ZERO = 'zero'

MAX_RANGE = 1e12


def say(number):
    if number < 0 or number >= MAX_RANGE:
        raise ValueError("input out of range")
    if number == 0:
        return ZERO

    output = []
    # iterate 1000^n values
    for th_val, th_say in sorted(THOUSANDS.items(), reverse=True):
        units = number // th_val
        if not units:
            continue

        # iterate 0 < val < 1000 values
        for num_val, num_say in sorted(NUMS.items(), reverse=True):
            digits = units // num_val
            if not digits:
                continue

            if num_val == 100:
                output.append(NUMS[digits])
            output.append(num_say)
            units %= num_val

        # remove hyphen if there is no values < 10
        if output[-1][-1] == '-':
            output[-1] = output[-1][:-1]

        output.append(th_say)
        number %= th_val

    return ' '.join(output).replace('- ', '-').strip()
