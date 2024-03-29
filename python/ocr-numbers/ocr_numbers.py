NUMBERS = {
    (' _ ', '| |', '|_|', '   '): '0',
    ('   ', '  |', '  |', '   '): '1',
    (' _ ', ' _|', '|_ ', '   '): '2',
    (' _ ', ' _|', ' _|', '   '): '3',
    ('   ', '|_|', '  |', '   '): '4',
    (' _ ', '|_ ', ' _|', '   '): '5',
    (' _ ', '|_ ', '|_|', '   '): '6',
    (' _ ', '  |', '  |', '   '): '7',
    (' _ ', '|_|', '|_|', '   '): '8',
    (' _ ', '|_|', ' _|', '   '): '9',
}

NUM_WIDTH = 3
NUM_HEIGHT = 4


def convert(input_grid):
    rows = len(input_grid)
    if rows % NUM_HEIGHT:
        raise ValueError("Number of input lines is not a multiple of four")
    output, splits = [], []
    for index, row in enumerate(input_grid):
        splits.append([])
        cols = len(row)
        if cols % NUM_WIDTH:
            raise ValueError("Number of input columns is not a multiple of three")
        for line in range(0, cols, NUM_WIDTH):
            splits[index % NUM_HEIGHT].append(row[line:line+NUM_WIDTH])
        if index % NUM_HEIGHT == NUM_HEIGHT - 1:
            output.append(''.join([NUMBERS[value] if value in NUMBERS else '?'
                                   for value in zip(*splits)]))
            splits = []
    return ','.join(output)
