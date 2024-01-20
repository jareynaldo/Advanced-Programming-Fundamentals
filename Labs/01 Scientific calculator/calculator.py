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



# prompts users for choice from the menu
def askForMenuSelection():
    print("Enter Menu Selection: ", end="")
    userchoice = input()

    return int(userchoice)

# prompts users for what two numbers the opperations
# should be done with
def askForNumbers():
    print("Enter first operand: ", end="")
    firstNumber = float(input())
    print("Enter second operand: ", end="")
    secondNumber = float(input())
    print()

    return firstNumber, secondNumber

# determines which value was chosen from the menu
def whichValue(userChoice, firstValue, secondValue):
    if(userChoice == 1):
        return addition(firstValue, secondValue)

    elif(userChoice == 2):
        return subtraction(firstValue, secondValue)

    elif(userChoice == 3):
        return multiplication(fisrstValue, secondValue)

    elif(userChoice == 4):
        return division(firstValue, secondValue)

    elif(userChoice == 5):
        return exponentiation(firstValue, secondValue)

    else:
        return logarithm(firstValue, secondValue)






def main():
    userChoice = 1
    checker = True

    total = 0
    counter = 0
    while checker:
        printMenu()
        userChoice = askForMenuSelection()
        if userChoice == 0:
            quit()
        choiceOne, ChoiceTwo = askForNumbers()

        if(userChoice != 7):
            whichValue()


        print(choiceOne, ChoiceTwo)



# Press the green button in the gutter to run the script.
if __name__ == '__main__':
    main()
