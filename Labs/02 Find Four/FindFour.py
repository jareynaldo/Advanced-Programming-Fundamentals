# Author: Jose Reynaldo
# Date: 25/1/23

# will check if it's a string here bc i could not get it to work otherwise
def askForHeight():
    print("Enter height of board (rows): ", end="")
    height = input()
    if height.isdigit():
        return int(height)
    else:
        while isinstance(height, str):
            print("Error: not a number!")
            height = askForHeight()
    return height



def askForWidth():
    print("Enter width of board (columns): ", end="")
    width = input()
    if width.isdigit():
        return int(width)
    else:
        while isinstance(width, str):
            print("Error: not a number!")
            width = askForWidth()
    return width


def askForDimensions():
    height = int(askForHeight())


    while height < 4:
        print("Error: height must be at least 4!")
        height = askForHeight()

    while height > 25:
        print("Error: height can be at most 25!")
        height = askForHeight()


    width = askForWidth()
    while width < 4:
        print("Error: width must be at least 4!")
        width = askForWidth()
    while width > 25:
        print("Error: width can be at most 25!")
        width = askForWidth()

    return height, width


def get_initial_board(rows, columns):
    board = []
    for row in range(rows):
        row = []
        for col in range(columns):
            row.append(".")
        board.append(row)

    return board


def main():
    checker = True
    while checker:
        print("Welcome to Find Four!")
        print("---------------------")

        height, width = askForDimensions()

        board = get_initial_board(height, width)

        print(board)
        checker = False


if __name__ == '__main__':
    main()
