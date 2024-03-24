def transpose(lines):
    if not lines:
        return ''

    lines = lines.split('\n')
    max_line_length = max([len(line) for line in lines])
    output = [[] for _ in range(max_line_length)]
    cur_len_line = 0
    for index in range(max_line_length - 1, -1, -1):
        output[index] = [' ' for _ in range(len(lines))]
        for lindex, line in enumerate(lines):
            if index < len(line):
                output[index][lindex] = line[index]
        # check the last space
        while len(output[index]) > cur_len_line:
            if output[index][-1] == ' ':
                output[index].pop()
            else:
                cur_len_line = len(output[index])
                break

    return '\n'.join([''.join(line) for line in output])
