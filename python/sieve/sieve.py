def primes(limit):
    prime_map = {v: True for v in range(2, limit + 1)}
    for num in range(2, limit + 1):
        if not prime_map[num]:
            continue

        not_prime = num
        while not_prime * num <= limit:
            prime_map[not_prime * num] = False
            not_prime += 1

    return [prime for prime, is_prime in prime_map.items() if is_prime]
