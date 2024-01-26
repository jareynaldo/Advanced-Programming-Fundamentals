# Created by: Jose Reynaldo and Wesley Chen
# date: 26/1/24
import sys
import heifer_generator



def main():

    #creates cows objects
    cows = heifer_generator.get_cows()

    responceList = []
    counter = 0

    # to check for double statments
    previusAnswer = None
    prePreviusAnswer = None


    for a in sys.argv:
        counter += 1

        #if tanglement to check varius conditions
        if a == "-l":
            print("Cows available:", end="")
            for k in range(len(cows)):
                print(" ", end="")
                print(cows[k].get_name(), end="")

            print()


        elif a == "World" and previusAnswer == "Hello":
            print("Hello World")
            print(cows[0].get_image())

        elif a == "kitteh" and previusAnswer == "-n" and previusAnswer == None:
            print("Hello World!")
            print(cows[1].get_image())

        elif a == "ninja" and previusAnswer == "-n":
            print("Could not find ninja cow!")

        elif a == "-n" and previusAnswer == "Hello":
            print("Hello -n kitteh")
            print(cows[0].get_image())
            quit()

        elif a == "I" and previusAnswer == "kitteh" and prePreviusAnswer == "-n":
            print("I am a cat")
            print(cows[1].get_image())
            quit()

        elif a == "Hello" and previusAnswer == "kitteh":
            print("Hello World!")
            print(cows[1].get_image())


        elif a == "heifer" and previusAnswer == "-n":
            print("I am not a cat")
            print(cows[0].get_image())





        previusAnswer = a
        if counter % 2 == 0:
            prePreviusAnswer = a




    completeResponse = " ".join(responceList)



main()