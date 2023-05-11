# TODO
from cs50 import get_float

count = 0

while True:
    cash = get_float("Change owed: ")
    if cash > 0:
        break

cents = round(cash * 100)
while cents > 0:
    if cents >= 25:
        cents = cents - 25
        count += 1
    elif cents >= 10:
        cents -= 10
        count += 1
    elif cents >= 5:
        cents = cents - 5
        count += 1
    elif cents >= 1:
        cents = cents - 1
        count = count + 1

print(count)