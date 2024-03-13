def prime(number):
    if not number:
        raise ValueError('there is no zeroth prime')

    primes, candidate = [2], 3

    while len(primes) < number:
        is_prime = True

        for prime in primes:
            if candidate % prime == 0:
                is_prime = False
                break
            if prime * prime > candidate:
                break

        if is_prime:
            primes.append(candidate)

        candidate += 2

    return primes[-1]
