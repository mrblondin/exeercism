def saddle_points(matrix):
    min_values, max_values = {}, {}
    for rindex, row in enumerate(matrix):
        if len(matrix[0]) != len(row):
            raise ValueError("irregular matrix")
        for cindex, col in enumerate(row):
            if cindex not in min_values or \
                    matrix[min_values[cindex][0]][cindex] > col:
                min_values[cindex] = [rindex]
            elif matrix[min_values[cindex][0]][cindex] == col:
                min_values[cindex].append(rindex)
            if rindex not in max_values or \
                    matrix[rindex][max_values[rindex][0]] < col:
                max_values[rindex] = [cindex]
            elif matrix[rindex][max_values[rindex][0]] == col:
                max_values[rindex].append(cindex)

    return [{'row': row + 1, 'column': col + 1} for row, cols
            in max_values.items() for col in cols if row in min_values[col]]
