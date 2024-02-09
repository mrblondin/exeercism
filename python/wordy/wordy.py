import re

GREETING = "What is"


def plus(x, y): return x + y
def minus(x, y): return x - y
def multiply(x, y): return x * y
def divide(x, y): return x / y


LOOKUP = {
    "plus": plus,
    "minus": minus,
    "multiplied": multiply,
    "divided": divide
}


def answer(question):
    if not question.startswith(GREETING):
        raise ValueError("unknown operation")

    pattern_num = r'^-?\d+$'
    pattern_replace = rf'{GREETING}|\?|by '

    question = re.sub(pattern_replace, "", question)
    q_array = question.strip().split(" ")

    # first number
    if not re.match(pattern_num, q_array[0]):
        raise ValueError("syntax error")
    sum = int(q_array.pop(0))

    while q_array:
        if re.match(pattern_num, q_array[0]):
            raise ValueError("syntax error")

        if q_array[0] in LOOKUP:
            val = 0
            if len(q_array) < 2 or not re.match(pattern_num, q_array[1]):
                raise ValueError("syntax error")

            val = int(q_array[1])

            sum = LOOKUP[q_array.pop(0)](sum, val)
            q_array.pop(0)
        else:
            raise ValueError("unknown operation")

    return sum
