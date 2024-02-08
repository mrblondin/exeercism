import re


def is_valid(isbn):
    sum = 0
    pattern = r'^\d-?\d{3}-?\d{5}-?[X\d]$'
    if not re.match(pattern, isbn):
        return False

    code = [*isbn.replace('-', '')]
    code.reverse()

    if code[0] == 'X':
        code[0] = 10

    for index, var in enumerate(code):
        sum += (index + 1) * int(var)

    return not sum % 11
