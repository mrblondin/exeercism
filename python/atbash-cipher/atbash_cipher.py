from string import ascii_lowercase


def encode(plain_text):
    return ''.join([('' if index % 5 else ' ') + ll
                    for index, ll in enumerate(code(plain_text))]).strip()


def decode(ciphered_text):
    return code(ciphered_text)


def code(text):
    c_map = build_cipher_map()
    return ''.join([(c_map[ll] if ll.isalpha() else ll)
                    for ll in text.lower() if ll.isalnum()])


def build_cipher_map():
    return dict(zip(ascii_lowercase, ascii_lowercase[::-1]))
