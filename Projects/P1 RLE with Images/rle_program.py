# Author: Jose Reynaldo
# Date: 12/2/24
# This project is intended to teach the basics of RLE

import console_gfx
import re


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

def count_runs(flatData):
    prev = 45
    counter = 0
    for i in range(len(flatData)):
        if flatData[i] != prev:
                counter += 1
        prev = flatData[i]

    return counter


def to_hex_string(data_in):
    data_out = []
    values = [0, 1, 2, 3, 4, 5, 6, 7, 8, 9, "a", "b", "c", "d", "e", "f", "g"]
    for counter in range(len(data_in)):
        for i in range(16):
            if data_in[counter] == i:
                data_out.append(str(values[i]))
    return "".join(data_out)

def to_hex_string_single_val(data_in):

    values = [0, 1, 2, 3, 4, 5, 6, 7, 8, 9, "a", "b", "c", "d", "e", "f", "g"]

    for i in range(16):
        if str(data_in) == str(i):
            data_in = str(values[i])
    return data_in



def encode_rle(data_in):
    data_out = ["b'"]
    runs = count_runs(data_in)


    how_many_instances = 0
    last_char = data_in[0]
    counter = 0
    # for however many indivdual character sequences you have (runs)
    # the program will loop through them, adding one to the how_many_instances
    # var until they no longer equal each other. Then the instances will be uploaded
    # to the data_out list and the actual value will be converted to hex
    for i in range(runs):

        while data_in[counter] == last_char:

            how_many_instances += 1
            counter += 1
            last_char = data_in[counter - 1]
            if counter == len(data_in):
                counter -= 1
                last_char = None

        append_string = r"\x0" + to_hex_string_single_val(how_many_instances)
        data_out.append(append_string)

        append_string = r"\x0" + to_hex_string_single_val(data_in[counter - 1])
        data_out.append(append_string)
        how_many_instances = 0
        last_char = data_in[counter]

    return "".join(data_out)

def get_undecoded_length(data_in):
    data_out = 0
    for i in range(len(data_in)):
        if i % 2 == 0:
            data_out += data_in[i]
    return data_out

def decode_rle(data_in):
    data_out = ["b'"]
    for i in range(len(data_in)):
        if i % 2 == 0:
            for j in range(data_in[i]):
                to_append = "\\x0"  + str(to_hex_string_single_val(data_in[i+1 ]))
                data_out.append(to_append)

    data_out.append("'")
    return "".join(data_out)

def string_to_data(data_in):
    data_out = ["b'"]
    split = [*data_in]

    for i in range(len(split)):
        append = "\\0" + split[i]
        data_out.append(append)

    data_out.append("'")
    return "".join(data_out)

def to_rle_string(data_in):
    data_out = []
    for i in range(len(data_in)):
        if i % 2 == 0:
           data_out.append(str(data_in[i]))
        else:
            append = to_hex_string_single_val(data_in[i])
            if i != len(data_in) - 1:
                append= append + ":"
            data_out.append(append)
    return "".join(data_out)

def string_to_rle(data_in):
    data_out = [*data_in]
    counter = []
    j = 0
    for i, value in enumerate(data_out):

        if value == ":":
            #gets all the elements prior to the hex value
            #and stores them in counter
            for k in range(i - 1):
                counter.append(data_out[k])
            data_out.pop(i)
            data_out.pop(j)
            data_out[j] = "".join(counter)
            j = i
            i -= 1


    #changes every value to hex
    for z in range(len(data_out)):
        bruh = data_out[z]
        data_out[z] = to_hex_string_single_val(bruh)

    return "b'\\x0" + "\\x0".join(data_out) + "'"




def main():
    print("Welcome to the RLE image encoder!")
    print()
    print("Displaying Spectrum Image:")
    image_data = [16, 1, 0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16]
    console_gfx.display_image(image_data)

    current_data = None
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

        elif int(user_choice) == 0:
            checker = False

        elif int(user_choice) == 1:
            print("Enter name of file to load: ", end="")
            file_name = input()
            current_data = console_gfx.load_file(file_name)

        elif int(user_choice) == 2:
            current_data = console_gfx.TEST_IMAGE
            print("Test image data loaded.")

        elif int(user_choice) == 3:
            print("Enter an RLE string to be decoded: ", end="")
            undecoded_str = input()

            current_data = string_to_rle(undecoded_str)

        elif int(user_choice) == 4:
            print("Enter the hex string holding RLE data: ", end="")
            undecoded_str = input()
            current_data = string_to_data(undecoded_str)
            print("RLE decoded length: " + str(len(undecoded_str)))

        elif int(user_choice) == 5:
            print("Enter the hex string holding flat data: ", end="")
            undecoded_str = input()
            current_data = undecoded_str

        elif int(user_choice) == 6:
            print("Displaying image...")
            if current_data == None:
                print("(no data)")
            else:
                console_gfx.display_image(current_data)

        elif int(user_choice) == 7:
            print("RLE representation:")
        elif int(user_choice) == 8:
            print("RLE hex values:")
        elif int(user_choice) == 9:
            print("Flat hex values:")








# Press the green button in the gutter to run the script.
if __name__ == '__main__':
    main()

