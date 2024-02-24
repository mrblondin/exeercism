import datetime
GIGASECOND = 1_000_000_000


def add(moment):
    return moment + datetime.timedelta(seconds=GIGASECOND)
