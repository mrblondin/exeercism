def append(list1, list2):
    list1.extend(list2)
    return list1


def concat(lists):
    return foldl(lambda acc, curr: append(acc, curr), lists, [])


def filter(function, list):
    return [val for val in list if function(val)]


def length(list):
    return sum([1 for _ in list])


def map(function, list):
    return [function(ll) for ll in list]


def foldl(function, list, initial):
    for ll in list:
        initial = function(initial, ll)
    return initial


def foldr(function, list, initial):
    return foldl(function, reverse(list), initial)


def reverse(list):
    return [list[len(list) - 1 - i] for i in range(len(list))]
