class HighScores:
    def __init__(self, scores):
        self.scores = scores
        self.scores_sorted = sorted(scores, reverse=True)
        print(self.scores_sorted)

    def personal_top_three(self):
        return self.scores_sorted[0:3]

    def personal_best(self):
        return self.scores_sorted[0]

    def latest(self):
        return self.scores[-1]
