class Queen:
    def __init__(self, row, column):
        if row < 0:
            raise ValueError("row not positive")
        if column < 0:
            raise ValueError("column not positive")
        if row > 7:
            raise ValueError("row not on board")
        if column > 7:
            raise ValueError("column not on board")

        self.row, self.column = row, column

    def can_attack(self, another_queen):
        q1, q2 = self, another_queen

        if q1.row == q2.row and q1.column == q2.column:
            raise ValueError("Invalid queen position: both queens in the same square")

        if q1.row == q2.row or q1.column == q2.column:
            return True
        elif abs(q1.row - q2.row) == abs(q1.column - q2.column):
            return True

        return False
