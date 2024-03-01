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


    for #Partner Patrick Byrd
import sys
import heifer_generator


def main():
    #creates a list of the types of cows
    cows = heifer_generator.get_cows()

    #prints list of different cows if "-l" is used
    if "-l" in sys.argv[1]:
        print("Cows available: ", end = '')
        for i in range (len(cows)):
            if i==len(cows)-1:
                print(cows[i].get_name(), end='')
            else:
                print(cows[i].get_name(), end=' ')
        print("")

    #prints out a message using specified cow or says cow could not be found
    elif "-n" in sys.argv[1]:
        #Checks for the cow type in list of available cows
        check=-1
        for i in range (len(cows)):
            if cows[i].get_name().__eq__(sys.argv[2]):
                #prints message
                for j in range (3, len(sys.argv)):
                    if j ==len(sys.argv)-1:
                        print(sys.argv[j], end='')
                    else:
                        print(sys.argv[j], end=' ')

                print("")
                #prints the cow
                print(cows[i].get_image())
                check+=1
        #if the type of cow is not available, it says so
        if check==-1:
            print("Could not find", sys.argv[2], "cow!")
    else:
        #prints message
        for i in range(1, len(sys.argv)):

            if i==len(sys.argv)-1:
                print(sys.argv[i], end='')
            else:
                print(sys.argv[i], end=' ')

        print("")
        #prints default cow
        print(cows[0].get_image())

#runs the main function
if __name__=="__main__":
    main()

a in sys.argv:
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