DEFICIENT = 'deficient'


def classify(number: int) -> str:
    """ A perfect number equals the sum of its positive divisors.

    :param number: int a positive integer
    :return: str the classification of the input integer
    """

    if number < 1:
        raise ValueError("Classification is only possible for \
positive integers.")

    factors = set((1,))
    n = 2
    while n < number / n:
        if number % n == 0:
            factors = set((*factors, n, number // n))
        n += 1

    factors.discard(number)

    return 'perfect' if sum(factors) == number \
        else 'abundant' if sum(factors) > number \
        else DEFICIENT
