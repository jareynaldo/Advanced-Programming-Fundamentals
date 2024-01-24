# Authors: Jose Reynaldo and Olusola Awonusonu
# Date: January 19th, 2023
import math


# will print the menu
def printMenu():
    print("Calculator Menu")
    print("---------------")
    print("0. Exit Program")
    print("1. Addition")
    print("2. Subtraction")
    print("3. Multiplication")
    print("4. Division")
    print("5. Exponentiation")
    print("6. Logarithm")
    print("7. Display Average \n")


def printLastItem(lastItem):
    print("Current Result: " + str(lastItem) + "\n")



def addition(one, two):
    return one + two

def subtraction(one, two):
    return one - two

def multiplication(one, two):
    return one *two

def division(one, two):
    return one / two

def exponentiation(one, two):
    return one ** two

def logarithm(base, x):
    return math.log(x, base)


def findAverage(total, counter):
    if total != 0:
        print("Sum of calculations: " + str(total))
        print("Number of calculations: " + str(total))
        print("Average of calculations: " + str(total/counter))

        return total / counter

    else:
        print("Error: No calculations yet to average!\n")



# prompts users for choice from the menu
def askForMenuSelection():
    print("Enter Menu Selection: ", end="")
    userchoice = input()

    return int(userchoice)


# prompts users for what two numbers the opperations should be done with
def askForNumbers():
    print("Enter first operand: ", end="")
    firstNumber = float(input())

    if firstNumber == 0:
        print("Error: Invalid selection!")
        quit()

    print("Enter second operand: ", end="")
    secondNumber = float(input())
    if secondNumber == 0:
        print("Error: Invalid selection!")
        quit()

    print()

    return firstNumber, secondNumber


# determines which value was chosen from the menu
def whichValue (userChoice, firstValue, secondValue):
    if userChoice == 1:
        return addition(firstValue, secondValue)

    elif userChoice == 2:
        return subtraction(firstValue, secondValue)

    elif userChoice == 3:
        return multiplication(firstValue, secondValue)

    elif userChoice == 4:
        return division(firstValue, secondValue)

    elif userChoice == 5:
        return exponentiation(firstValue, secondValue)
    else:
        return logarithm(firstValue, secondValue)


def main():
    userChoice = 1
    checker = True
    total = 0
    counter = 0
    lastValue = 0

    while checker:
        if total ==0:
            printLastItem(float(lastValue))
        printMenu()
        userChoice = askForMenuSelection()

        if userChoice == 0:
            print("Thanks for using this calculator. Goodbye!")
            quit()

        elif userChoice == 7:
            findAverage(total, counter)
        else:
            # first figures out which opperation should be done, then the opperation is done and printed
            # then last value of opperation is uppended to total and counter is updated
            firstNumber, secondNumber = askForNumbers()
            lastValue = whichValue(userChoice, firstNumber, secondNumber)
            total += lastValue
            counter += 1
            printLastItem(lastValue)




if __name__ == '__main__':
    main()
