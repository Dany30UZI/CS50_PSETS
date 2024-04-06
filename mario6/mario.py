from cs50 import get_int


def main():
    while True:
        height = get_int("Height: ")
        if height >= 1 and height <= 8:
            break

    for i in range(height, 0, -1):
        printRow(i-1, height-(i-1))


def printRow(dot, hash):
    for i in range(dot):
        print(" ", end="")

    for j in range(hash):
        print("#", end="")

    print()


main()
