from collections import defaultdict


class School:
    def __init__(self):
        self._roster = defaultdict(list)
        self.names = set()
        self.added_status = []

    def add_student(self, name, grade):
        if name in self.names:
            self.added_status.append(False)
            return
        self._roster[grade].append(name)
        self._roster[grade].sort()
        self.names.add(name)
        self.added_status.append(True)

    def roster(self):
        return [name for grade in sorted(self._roster.keys())
                for name in self._roster[grade]]

    def grade(self, grade_number):
        return self._roster[grade_number]

    def added(self):
        return self.added_status
