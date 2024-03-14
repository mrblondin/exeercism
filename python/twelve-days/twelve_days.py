CUMULATION_MAP = {
    1: ['first', 'a Partridge in a Pear Tree'],
    2: ['second', 'two Turtle Doves'],
    3: ['third', 'three French Hens'],
    4: ['fourth', 'four Calling Birds'],
    5: ['fifth', 'five Gold Rings'],
    6: ['sixth', 'six Geese-a-Laying'],
    7: ['seventh', 'seven Swans-a-Swimming'],
    8: ['eighth', 'eight Maids-a-Milking'],
    9: ['ninth', 'nine Ladies Dancing'],
    10: ['tenth', 'ten Lords-a-Leaping'],
    11: ['eleventh', 'eleven Pipers Piping'],
    12: ['twelfth', 'twelve Drummers Drumming'],
}


def recite(start_verse, end_verse):
    output = []

    def start(nth): return f'On the {nth} day of Christmas my true love gave \
to me: '

    def build_verse(verse): return CUMULATION_MAP[verse][1] + \
        (', ' if verse > 2 else (', and ' if verse == 2 else '')) + \
        (build_verse(verse - 1) if verse > 1 else '.')

    for verse in range(start_verse, end_verse + 1):
        output.append(start(CUMULATION_MAP[verse][0]) + build_verse(verse))
    return output
