def commands(binary_str):
    ACTIONS = ['wink', 'double blink', 'close your eyes', 'jump']
    binary = int(binary_str, 2)
    response = []
    for i in range(len(ACTIONS)):
        if binary & 1 << i:
            response.append(ACTIONS[i])

    if binary & 1 << 4:
        response.reverse()

    return response
