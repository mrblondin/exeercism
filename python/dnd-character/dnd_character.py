import random

MIN_VAL = 3
MAX_VAL = 18


class Character:
    def __init__(self):
        self.strength = self.ability()
        self.dexterity = self.ability()
        self.constitution = self.ability()
        self.intelligence = self.ability()
        self.wisdom = self.ability()
        self.charisma = self.ability()
        self.hitpoints = 10 + modifier(self.constitution)

    def ability(self):
        return random.randrange(MIN_VAL, MAX_VAL)


def modifier(constitution):
    return (constitution - 10) // 2
