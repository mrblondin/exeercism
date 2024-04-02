def triplets_with_sum(number):
    # a^2 + b^2 = (N - c)^2
    # b = (N^2 - 2 N * a) / 2 * (N - a)
    a, b, output = 2, number, []
    while a < b:
        b = (number * number - 2 * number * a) / (2 * (number - a))
        if not b % 1:
            output.append([a, b, number - a - b])
        a += 1
    return output
