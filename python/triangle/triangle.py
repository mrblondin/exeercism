def is_real_triangle(sides):
    return all(sides) and sum(sides) > 2 * max(sides)


def equilateral(sides):
    return len(set(sides)) == 1 and is_real_triangle(sides)


def isosceles(sides):
    return len(set(sides)) <= 2 and is_real_triangle(sides)


def scalene(sides):
    return len(set(sides)) == 3 and is_real_triangle(sides)
