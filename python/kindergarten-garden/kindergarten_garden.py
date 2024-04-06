CHILDREN = ['Alice', 'Bob', 'Charlie', 'David', 'Eve', 'Fred', 'Ginny',
            'Harriet', 'Ileana', 'Joseph', 'Kincaid', 'Larry']
PLANTS = {'V': 'Violets', 'R': 'Radishes', 'C': 'Clover', 'G': 'Grass'}
PLANTS_PP = 2


class Garden:
    def __init__(self, diagram, students=CHILDREN):
        self.students = sorted(students)
        self.diagram = diagram.split('\n')

    def plants(self, name):
        if name in self.students:
            index = self.students.index(name)
            return [PLANTS[letter] for row in self.diagram
                    for letter in row[PLANTS_PP*index:PLANTS_PP*index+PLANTS_PP]]
        return []
