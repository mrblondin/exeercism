from collections import Counter

YACHT = 12
ONES = 1
TWOS = 2
THREES = 3
FOURS = 4
FIVES = 5
SIXES = 6
FULL_HOUSE = 7
FOUR_OF_A_KIND = 8
LITTLE_STRAIGHT = 9
BIG_STRAIGHT = 10
CHOICE = 11


def score(dice, category):
    if category >= ONES and category <= SIXES:
        return dice.count(category) * category
    elif category == FOUR_OF_A_KIND:
        return max([key * 4 for key, value in Counter(dice).items()
                    if value > 3] + [0])
    elif category == FULL_HOUSE:
        counter = Counter(dice)
        if max(counter.values()) == 3 and min(counter.values()) == 2:
            return sum([count * key for key, count in counter.items()])
        return 0
    elif category == CHOICE:
        return sum([count * key for key, count in Counter(dice).items()])
    elif category == YACHT:
        return 50 if len(set(dice)) == 1 else 0
    elif category == LITTLE_STRAIGHT or category == BIG_STRAIGHT:
        return 30 if len(set(dice)) == 5 and \
            (6 if category == LITTLE_STRAIGHT else 1) not in dice else 0
