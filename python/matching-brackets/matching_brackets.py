BRACKETS = {'[': ']', '{': '}', '(': ')'}


def is_paired(input_string):
    """
    Valid bracket sentence
    """
    stack = []
    open = BRACKETS.keys()
    close = BRACKETS.values()
    for s in input_string:
        if s in open:
            stack.append(s)

        if s in close:
            if not stack or BRACKETS[stack.pop()] != s:
                return False

    return not stack
