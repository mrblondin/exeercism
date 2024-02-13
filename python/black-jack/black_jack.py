"""Functions to help play and score a game of blackjack.

How to play blackjack:    https://bicyclecards.com/how-to-play/blackjack/
"Standard" playing cards: https://en.wikipedia.org/wiki/Standard_52-card_deck
"""

ERROR = 0
BLACK_JACK = 21
ACE_MAX_VAL = 11
ACE_MIN_VAL = 1
PICTURES_VALS = ["10", "J", "Q", "K", "A"]


def value_of_card(card):
    """Determine the scoring value of a card.

    :param card: str - given card.
    :return: int - value of a given card.  See below for values.

    1.  'J', 'Q', or 'K' (otherwise known as "face cards") = 10
    2.  'A' (ace card) = 1
    3.  '2' - '10' = numerical value.
    """

    if card == "A":
        return 1
    if card in ["J", "Q", "K"]:
        return 10
    if int(card) in list(range(2, 11)):
        return int(card)

    return ERROR


def higher_card(card_one, card_two):
    """Determine which card has a higher value in the hand.

    :param card_one, card_two: str - cards dealt in hand.  See below for values.
    :return: str or tuple - resulting Tuple contains both cards if they are of equal value.

    1.  'J', 'Q', or 'K' (otherwise known as "face cards") = 10
    2.  'A' (ace card) = 1
    3.  '2' - '10' = numerical value.
    """

    _card_one = value_of_card(card_one)
    _card_two = value_of_card(card_two)

    if _card_one > _card_two:
        return card_one
    if _card_one < _card_two:
        return card_two

    return card_one, card_two


def value_of_ace(card_one, card_two):
    """Calculate the most advantageous value for the ace card.

    :param card_one, card_two: str - card dealt. See below for values.
    :return: int - either 1 or 11 value of the upcoming ace card.

    1.  'J', 'Q', or 'K' (otherwise known as "face cards") = 10
    2.  'A' (ace card) = 11 (if already in hand)
    3.  '2' - '10' = numerical value.
    """

    _card_one = value_of_card(card_one) if value_of_card(card_one) != 1 else 11
    _card_two = value_of_card(card_two) if value_of_card(card_two) != 1 else 11

    if (BLACK_JACK - _card_one - _card_two) >= ACE_MAX_VAL:
        return ACE_MAX_VAL

    return ACE_MIN_VAL


def is_blackjack(card_one, card_two):
    """Determine if the hand is a 'natural' or 'blackjack'.

    :param card_one, card_two: str - card dealt. See below for values.
    :return: bool - is the hand is a blackjack (two cards worth 21).

    1.  'J', 'Q', or 'K' (otherwise known as "face cards") = 10
    2.  'A' (ace card) = 11 (if already in hand)
    3.  '2' - '10' = numerical value.
    """

    if card_one in PICTURES_VALS and card_two in PICTURES_VALS \
            and value_of_card(card_one) != value_of_card(card_two):
        return True

    return False


def can_split_pairs(card_one, card_two):
    """Determine if a player can split their hand into two hands.

    :param card_one, card_two: str - cards dealt.
    :return: bool - can the hand be split into two pairs? (i.e. cards are of the same value).
    """

    return value_of_card(card_one) == value_of_card(card_two)


def can_double_down(card_one, card_two):

    return 8 < value_of_card(card_one) + value_of_card(card_two) < 12
