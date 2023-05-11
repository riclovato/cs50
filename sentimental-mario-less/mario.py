# TODO
from cs50 import get_int


def main():

    while True:
        height = get_int("height: ")
        if height > 0 and height <= 8:
            break

    for i in range(height):
        print(" " * (height - 1 - i), end="")
        print("#"*(i+1))


main()
