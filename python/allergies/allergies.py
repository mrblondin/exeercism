CODES = {
    'eggs': 1,
    'peanuts': 2,
    'shellfish': 4,
    'strawberries': 8,
    'tomatoes': 16,
    'chocolate': 32,
    'pollen': 64,
    'cats': 128
}


class Allergies:

    def __init__(self, score):
        self.score = score

    def allergic_to(self, item):
        return True if self.score & CODES[item] else False

    @property
    def lst(self):
        return [name for name, code in CODES.items() if code & self.score]
