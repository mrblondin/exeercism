def valid_number(f):
    def wrapper(number):
        if number > 64 or number < 1:
            raise ValueError("square must be between 1 and 64")
        return f(number)
    return wrapper


@valid_number
def square(number):
    return 1 << (number - 1)


def total():
    return (1 << 64) - 1
