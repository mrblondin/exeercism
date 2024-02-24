def square_root(number):
    """ Find square root whithout using standart functions
    Binary search is used for the task

    :param number:int
    :return :int
    """
    if number == 1:
        return 1

    left = 2
    right = number

    while right > left:
        mid = (right + left) // 2
        sqr = mid * mid
        if sqr < number:
            left = mid + 1
        elif sqr > number:
            right = mid
        else:
            return mid

    return -1
