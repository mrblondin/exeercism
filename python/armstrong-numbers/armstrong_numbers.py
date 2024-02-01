def is_armstrong_number(number):
    return sum([int(num) ** len(str(number)) for num in str(number)]) == number
