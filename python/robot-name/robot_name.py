from string import ascii_uppercase
from itertools import product
import random

LETTER_COUNT = 26
ASCII_A = 65


class Robot:
    def __init__(self):
        self.buffer = []
        self.generate_names()
        self.shuffle_names()
        self.reset()

    def reset(self):
        self.name = self.buffer.pop()

    def generate_names(self):
        # fill in the buffer with possible names
        letters = (f'{letter1}{letter2}' for letter1, letter2
                   in product(ascii_uppercase, ascii_uppercase))
        numbers = (str(num).zfill(3) for num in range(0, 1000))
        self.buffer = [f'{ltrs}{digits}'
                       for ltrs, digits in product(letters, numbers)]

    def shuffle_names(self):
        # shuffle buffer Fisher–Yates algorithm
        for idx in range(len(self.buffer) - 1, -1, -1):
            randIndex = random.randrange(0, len(self.buffer))
            self.buffer[idx], self.buffer[randIndex] = \
                self.buffer[randIndex], self.buffer[idx]
