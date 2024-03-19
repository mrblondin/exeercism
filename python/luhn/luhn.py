import re


class Luhn:
    def __init__(self, card_num):
        self.num = card_num.replace(' ', '')[::-1]

    def valid(self):
        return bool(re.fullmatch(r'\d{2,}', self.num)) and \
            not (sum([((int(num) * 2 - 9 if int(num) * 2 > 9
                      else int(num) * 2) if index % 2 else int(num))
                     for index, num in enumerate(self.num)]) % 10)
