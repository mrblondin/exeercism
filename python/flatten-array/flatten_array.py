def flatten(iterable):
    arr = []

    def make_flat(iterable, arr):
        for val in iterable:
            if type(val) is list:
                make_flat(val, arr)
            elif val is not None:
                arr.append(val)
    make_flat(iterable, arr)
    return arr
