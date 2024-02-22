def find(search_list, value):
    left, right = 0, len(search_list)
    mid = (right + left) // 2

    while right > left:
        if search_list[mid] < value:
            left = mid + 1
        elif search_list[mid] > value:
            right = mid
        else:
            return mid

        mid = (right + left) // 2

    raise ValueError("value not in array")
