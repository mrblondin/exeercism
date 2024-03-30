EAST = 0
NORTH = 1
WEST = 2
SOUTH = 3
DIRECTIONS = {EAST: (1, 0), NORTH: (0, 1), WEST: (-1, 0), SOUTH: (0, -1)}
ROTATION = {'L': 1, 'R': -1}
ADVANCE = 'A'


class Robot:
    def __init__(self, direction=NORTH, x_pos=0, y_pos=0):
        self.coordinates = x_pos, y_pos
        self.direction = direction

    def move(self, movements):
        for movement in movements:
            if movement in ROTATION:
                self.direction = (self.direction + ROTATION[movement]) % 4
            elif movement == ADVANCE:
                self.coordinates = tuple(map(sum,
                    zip(self.coordinates, DIRECTIONS[self.direction])))
