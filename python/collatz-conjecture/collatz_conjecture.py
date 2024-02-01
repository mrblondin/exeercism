import itertools


def valid_number(f):
    def wrapper(number):
        if number < 1:
            raise ValueError("Only positive integers are allowed")
        return f(number)
    return wrapper


@valid_number
def steps(number):
    for step in itertools.count():
        if number == 1:
            break

        if number % 2 == 1:
            number = number * 3 + 1
        else:
            number /= 2

    return step
