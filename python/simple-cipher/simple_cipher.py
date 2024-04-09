import random
from itertools import cycle

DEFAULT_KEY_LENGTH = 100
CHAR_A = 97
ALFA_LENGTH = 26


class Cipher:
    def __init__(self, key=None):
        self.key = key
        if not self.key:
            self.key = ''.join([chr(random.randrange(97, 123))
                                for _ in range(0, DEFAULT_KEY_LENGTH)])
        self.key_length = len(self.key)

    def encode(self, text):
        return self.__code(text, 1)

    def decode(self, text):
        return self.__code(text, -1)

    def __code(self, text, side=1):
        return ''.join([chr((ord(char) + side * (ord(key)
                        - CHAR_A) - CHAR_A) % ALFA_LENGTH + CHAR_A)
                        for char, key in zip(text, cycle(self.key))])
