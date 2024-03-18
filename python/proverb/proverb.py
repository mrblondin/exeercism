def proverb(*input, qualifier):
    qualifier = qualifier + ' ' if qualifier else ''
    return [f'For want of a {word1} the {word2} was lost.'
            for word1, word2 in zip(input[:-1], input[1:])] + \
        [f'And all for the want of a {qualifier}{input[0]}.'] if input else []
