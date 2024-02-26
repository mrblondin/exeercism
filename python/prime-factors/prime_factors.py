def factors(value):
    output = []

    for prime in range(2, value + 1):
        while value % prime == 0:
            value /= prime
            output.append(prime)

        if value == 1:
            break

    return output
