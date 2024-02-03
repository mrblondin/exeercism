DROPS_SOUNDS = {3: "Pling", 5: "Plang", 7: "Plong"}


def convert(number):
    return ''.join([sound for key, sound in DROPS_SOUNDS.items()
                    if number % key == 0] or [str(number)])
