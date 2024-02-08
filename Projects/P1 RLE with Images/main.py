# Author: Jose Reynaldo
# Date: 12/2/24
# This project is intended to teach the basics of RLE

import console_gfx


def print_menu():
    print("RLE Menu")
    print("--------")
    print("0. Exit")
    print("1. Load File")
    print("2. Load Test Image")
    print("3. Read RLE String")
    print("4. Read RLE Hex String")
    print("5. Read Data Hex String")
    print("6. Display Image")
    print("7. Display RLE String")
    print("8. Display Hex RLE Data")
    print("9. Display Hex Flat Data")


def user_input_checker(user_input):

    if int(user_input) > 7:
        return 0
    elif int(user_input) < 0:
        return 0
    return 1




def main():
    print("Welcome to the RLE image encoder!")
    print()
    print("Displaying Spectrum Image:")
    image_data = [
        16,
        1,
        0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16]
    console_gfx.display_image(image_data)

    print()
    checker = True
    while checker:
        print()
        print_menu()
        print()
        print("Select a Menu Option: ", end="")
        user_choice = input()
        if user_input_checker(user_choice) == 0:
            print("Error! Invalid input.")
        elif int(user_choice) == 1:
            print("Enter name of file to load: ", end="")
            file_name = input()
            console_gfx.load_file(file_name)




# Press the green button in the gutter to run the script.
if __name__ == '__main__':
    main()

