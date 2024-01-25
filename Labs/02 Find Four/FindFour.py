# Author: Jose Reynaldo
# Date: 25/1/23

# determine height and will check if it's a string here bc i could not get it to work otherwise
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

#same thing as askForHeight except for width
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



# manages the asking for dimensions, and berefies it's within the right bounds
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

def print_board(board, height, width):

    for i in range(width + 2):
        #to determine the space at start and end
        if i == 0 or i == width + 1:
            print(" ", end="")
        else:
            print("__", end="")

    print()
    for i in range(height):
        print("|", end="")
        for j in range(width):
            print(board[i][j] + " ", end="")
        print("|")

    for k in range(width + 2):
        if k == 0 or k == width + 1:
            print(" ", end="")
        else:
            print("--", end="")

def isColInBound(choice, column):

    while choice < column or choice > column:
        print("Error: no such column!")
        height = playerOneSelection(column)



def playerOneSelection(column):

    print("Player 1 - Select a Column: ", end="")
    playerChoice = input()

    if playerChoice.isdigit():
        choice = int(playerChoice)
        returnVal = isColInBound(choice, column)
        return returnVal

    else:
        while isinstance(playerChoice, str):
            print("Error: not a number!")
            playerChoice = playerOneSelection(column)
    return playerChoice



def main():
    checker = True

    print("Welcome to Find Four!")
    print("---------------------")

    height, width = askForDimensions()

    board = get_initial_board(height, width)
    print_board(board, height, width)

    print()
    print("Player 1: x")
    print("Player 2: o")
    print()

    while checker:
        playerOneSelection(width)


        checker = False


if __name__ == '__main__':
    main()
