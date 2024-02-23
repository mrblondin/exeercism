ORBITAL_RATIO = {
    'earth': 1,
    'mercury': 0.2408467,
    'venus': 0.61519726,
    'mars': 1.8808158,
    'jupiter': 11.862615,
    'saturn': 29.447498,
    'uranus': 84.016846,
    'neptune': 164.79132
}


class SpaceAge:
    def __init__(self, seconds):
        for planet, ratio in ORBITAL_RATIO.items():
            setattr(self, f"on_{planet}", lambda ratio=ratio:
                    round(seconds / 31557600 / ratio, 2))
