RADIUS_TO_SCORE = {1: 10, 5: 5, 10: 1}


def score(x, y):
    return next((score for radius, score in RADIUS_TO_SCORE.items()
                if (x ** 2 + y ** 2) ** 0.5 <= radius), 0)
