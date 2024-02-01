def is_question(text): return text.endswith("?")
def is_yell(text): return text.isupper()
def is_silence(text): return not text
def is_yell_question(text): return is_yell(text) and is_question(text)
def is_default(text): return True


rules = [
    {"test": is_silence,        "res": "Fine. Be that way!"},
    {"test": is_yell_question,  "res": "Calm down, I know what I'm doing!"},
    {"test": is_yell,           "res": "Whoa, chill out!"},
    {"test": is_question,       "res": "Sure."},
    {"test": is_default,        "res": "Whatever."},
]


def response(hey_bob):
    hey_bob = hey_bob.rstrip()
    for rule in rules:
        if rule["test"](hey_bob):
            return rule["res"]
