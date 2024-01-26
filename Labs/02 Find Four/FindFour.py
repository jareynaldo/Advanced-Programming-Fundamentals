# Author: Jose Reynaldo
# Date: 25/1/23

# determine height and will check if it's a string here bc i could not get it to work otherwise
def askForHeight():
    print("Enter height of board (rows): ", end="")
    height = input()
    if height.isdigit():
        return int(height)
    elif int(height) < 0:
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
    elif int(width) < 0:
        return int(width)

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
    for o in range(height):
        print("|", end="")
        for j in range(width):
            print(board[o][j] + " ", end="")
        print("|")

    for k in range(width + 2):
        if k == 0 or k == width + 1:
            print(" ", end="")
        else:
            print("--", end="")

def isColInBoundOne(choice, column):

    if choice < 0 or choice >= column:
        print("Error: no such column!")
        choice = playerOneSelection(column)
    else:
        return choice
    return choice


def playerOneSelection(column):
    print()
    print("Player 1 - Select a Column: ", end="")
    playerChoice = input()

    if playerChoice.isdigit():
        playerChoice = int(playerChoice)
        return isColInBoundOne(playerChoice, column)
    elif int(playerChoice) < 0:
        playerChoice = int(playerChoice)
        return isColInBoundOne(playerChoice, column)
    else:
        while isinstance(playerChoice, str):
            print("Error: not a number!")
            playerChoice = playerOneSelection(column)
    return playerChoice


def isColInBoundTwo(choice, column):

    if choice < 0 or choice >= column:
        print("Error: no such column!")
        choice = playerOneSelection(column)
    else:
        return choice
    return choice

def playerTwoSelection(column):

    print("Player 2 - Select a Column: ", end="")
    playerChoice = input()

    if playerChoice.isdigit():
        playerChoice = int(playerChoice)
        return isColInBoundTwo(playerChoice, column)
    elif int(playerChoice) < 0:
        playerChoice = int(playerChoice)
        return isColInBoundTwo(playerChoice, column)
    else:
        while isinstance(playerChoice, str):
            print("Error: not a number!")
            playerChoice = playerOneSelection(column)
    return playerChoice



def insert_chip(board, column, chip):

    for row in range(len(board) -1, -1, -1):
        if board[row][column] == ".":
            board[row][column] = chip
            return board, row
    return board




def check_horizontal(board, chip, row):
    consecutive_count = 0
    for col in range(len(board[row])):
        if board[row][col] == chip:
            consecutive_count += 1
            if consecutive_count == 4:
                return True
        else:
            consecutive_count = 0
    return False


def check_vertical(board, chip, column):
    consecutive_count = 0
    for row in range(len(board)):
        if board[row][column] == chip:
            consecutive_count += 1
            if consecutive_count == 4:
                return True
        else:
            consecutive_count = 0
    return False


def check_diagonal_up(board, chip, row, column):
    consecutive_count = 0
    for i in range(min(row, column, len(board[row]) - column - 1) + 1):
        if board[row - i][column - i] == chip:
            consecutive_count += 1
            if consecutive_count == 4:
                return True
        else:
            consecutive_count = 0
    return False


def check_diagonal_down(board, chip, row, column):
    consecutive_count = 0
    for i in range(min(len(board) - row - 1, column, len(board[row]) - column - 1) + 1):
        if board[row + i][column - i] == chip:
            consecutive_count += 1
            if consecutive_count == 4:
                return True
        else:
            consecutive_count = 0
    return False


def is_win_state(chip, board, row, column):
    if check_horizontal(board, chip, row):
        return True

    if check_vertical(board, chip, column):
        return True

    if check_diagonal_up(board, chip, row, column):
        return True

    if check_diagonal_down(board, chip, row, column):
        return True

    return False

def is_board_full(board, width):
    returnValue = False
    counter = 0
    for j in range(width):
        if (board[0][j] != "."):
            counter += 1
    if counter == width:
        returnValue = True

    return False


def main():
    checker = False

    print("Welcome to Find Four!")
    print("---------------------")

    height, width = askForDimensions()

    board = get_initial_board(height, width)
    print_board(board, height, width)

    print()
    print("Player 1: x")
    print("Player 2: o")
    print()

    playerOneChip = "x"
    playertwoChip = "o"

    while checker != True:
        choiceOfOne = playerOneSelection(width)
        print()
        board, PlayerOneRow = insert_chip(board, choiceOfOne, playerOneChip)
        print_board(board, width, height)
        print()

        checker = is_win_state(playerOneChip, board, PlayerOneRow, choiceOfOne )

        if checker == True:
            print()
            print("Player 1 won the game!")
            quit()

        checker = is_board_full(board, width)
        if checker == True:
            print()
            print("Draw game! Players tied.")
            quit()

        choiceOfTwo = playerTwoSelection(width)
        print()
        board, row = insert_chip(board, choiceOfTwo, playertwoChip)
        print_board(board, width, height)
        print()

        checker = is_win_state(playerOneChip, board, PlayerOneRow, choiceOfTwo )
        if checker == True:
            print()
            print("Player 2 won the game!")
            quit()

        checker = is_board_full(board, width)
        if checker == True:
            print()
            print("Draw game! Players tied.")
            quit()




if __name__ == '__main__':
    main()
