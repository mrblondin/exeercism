import re


class PhoneNumber:
    def __init__(self, number):
        self.number = re.sub(r'^1|(^\+1)|[()\-\s\.]', '', number)

        if len(self.number) < 10:
            raise ValueError("must not be fewer than 10 digits")
        elif len(self.number) > 11:
            raise ValueError("must not be greater than 11 digits")
        elif len(self.number) == 11:
            raise ValueError("11 digits must start with 1")
        elif re.search(r'[^A-Za-z0-9]', self.number):
            raise ValueError("punctuations not permitted")
        elif re.search(r'[^\d]', self.number):
            raise ValueError("letters not permitted")
        elif int(self.number[0]) < 2:
            raise ValueError(f"area code cannot start with \
{'one' if int(self.number[0]) else 'zero'}")
        elif int(self.number[3]) < 2:
            raise ValueError(f"exchange code cannot start with \
{'one' if int(self.number[3]) else 'zero'}")
        self.area_code = self.number[0:3]

    def pretty(self):
        return f'({self.area_code})-{self.number[3:6]}-{self.number[6:10]}'
