def sum_of_multiples(limit, multiples):
    return sum(set([i * mul for mul in multiples if mul
                    for i in range(1, (limit - 1) // mul + 1)]))
