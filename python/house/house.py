RHYME = {
    1: 'lay in the house that Jack built.',
    2: 'ate the malt',
    3: 'killed the rat',
    4: 'worried the cat',
    5: 'tossed the dog',
    6: 'milked the cow with the crumpled horn',
    7: 'kissed the maiden all forlorn',
    8: 'married the man all tattered and torn',
    9: 'woke the priest all shaven and shorn',
    10: 'kept the rooster that crowed in the morn',
    11: 'belonged to the farmer sowing his corn',
    12: 'the horse and the hound and the horn'
}


def recite(start_verse, end_verse):
    arr = []

    def build(start_verse, end_verse, arr):
        if start_verse > end_verse:
            return None

        rhyme = 'This is ' + \
            RHYME[start_verse][RHYME[start_verse].index('the'):]
        for i in range(start_verse - 1, 0, -1):
            rhyme += ' that ' + RHYME[i]

        arr.append(rhyme)
        build(start_verse + 1, end_verse, arr)
        return arr

    return build(start_verse, end_verse, arr)
