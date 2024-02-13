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
    #checks if user input is in correct range
    if int(user_input) > 9:
        return 0
    elif int(user_input) < 0:
        return 0
    return 1

def count_runs(data_in):

    #counts how many individual instaces there are of each element,
    #and if there's a hex value multiple total by 2
    prev = data_in[0]
    counter = 1  # Start with 1 to count the first run
    multiple = 1

    for i in range(1, len(data_in)):
        if isinstance(data_in[i], str):
            multiple = 2
        if data_in[i] != prev:
            counter += 1
        prev = data_in[i]

    return counter * multiple


def to_hex_string(data_in):

    #converts decimals into hexedecimals
    data_out = []
    values = [0, 1, 2, 3, 4, 5, 6, 7, 8, 9, "a", "b", "c", "d", "e", "f", "g"]
    for counter in range(len(data_in)):
        for i in range(16):
            if data_in[counter] == i:
                data_out.append(str(values[i]))
    return "".join(data_out)

def to_hex_string_single_val(data_in):
    #above but for a single value
    values = [0, 1, 2, 3, 4, 5, 6, 7, 8, 9, "a", "b", "c", "d", "e", "f", "g"]
    for i in range(16):
        if str(data_in) == str(i):
            data_in = str(values[i])
    return data_in


def encode_rle(data_in):
    #will turn flat data into RLE format. If more than 15 instances start new line
    data_out = []
    runs = count_runs(data_in)

    how_many_instances = 0
    last_char = data_in[0]
    counter = 0

    for i in range(runs):
        while counter < len(data_in) and data_in[counter] == last_char:
            how_many_instances += 1
            counter += 1
            if how_many_instances == 15:
                data_out.append(how_many_instances)
                data_out.append(last_char)
                how_many_instances = 0

        data_out.append(how_many_instances)
        data_out.append(last_char)

        if counter < len(data_in):
            last_char = data_in[counter]
            how_many_instances = 0

    return bytes(data_out)


def get_decoded_length(data_in):

    #uses an RLE list to determine how many indivudal elements there are
    data_out = 0
    for i in range(len(data_in)):
        if i % 2 == 0:
            data_out += data_in[i]
    return data_out

def decode_rle(data_in):
    #Returns the decoded data set from RLE encoded data
    data_out = []
    for i in range(len(data_in)):
        if i % 2 == 0:
            for j in range(data_in[i]):
                data_out.append(data_in[i+1])


    return bytes(data_out)

def string_to_data(data_in):

    #Translates a string in hexadecimal format into byte data
    data_out = []
    split = [*data_in]
    values = [0, 1, 2, 3, 4, 5, 6, 7, 8, 9, "a", "b", "c", "d", "e", "f", "g"]
    for counter in range(len(split)):
        for i in range(16):
            if split[counter] == str(values[i]):
                data_out.append(i)
    return bytes(data_out)


def to_rle_string(rleData):
    #Translates RLE data into a human-readable representation
    data_out = []
    for i in range(0, len(rleData), 2):
        run_length = str(rleData[i])
        run_value_hex = to_hex_string_single_val(rleData[i + 1])

        run_str = f"{run_length}{run_value_hex}"

        if i != len(rleData) - 2:
            run_str += ":"

        data_out.append(run_str)

    return "".join(data_out)


def string_to_rle(data_in):
    #Translates a string in human-readable RLE format (with delimiters) into RLE byte data.
    split_data = data_in.split(":")
    data_out = []

    for i in range(len(split_data)):
        current_value = split_data[i]
        run_length_str, hex_val = current_value[:-1], current_value[-1]

        run_length = int(run_length_str)
        int_val = int(hex_val, 16)

        data_out.append(run_length)
        data_out.append(int_val)

    return bytes(data_out)



def main():
    print("Welcome to the RLE image encoder!")
    print()
    print("Displaying Spectrum Image:")
    image_data = console_gfx.TEST_RAINBOW
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
            undecoded_str = console_gfx.load_file(file_name)
            current_data = list(undecoded_str)

        elif int(user_choice) == 2:
            current_data = console_gfx.TEST_IMAGE

            print("Test image data loaded.")

        elif int(user_choice) == 3:

            print("Enter an RLE string to be decoded: ", end="")
            undecoded_str = input()
            current_data = string_to_rle(undecoded_str)

        elif int(user_choice) == 4:

            print("Enter the hex string holding RLE data: ", end="")
            undecoded_str = input().lower()

            undecoded_str = string_to_data(undecoded_str)
            undecoded_str = list(undecoded_str)
            counter = 0

            for i in range(len(undecoded_str)):
                if i % 2 == 0:
                    counter += undecoded_str[i]

            print("RLE decoded length: " + str(counter))
            current_data = list(decode_rle(undecoded_str))


        elif int(user_choice) == 5:

            print("Enter the hex string holding flat data: ", end="")
            undecoded_str = input()
            number_runs = count_runs(undecoded_str)
            print("Number of runs: " + str(number_runs))

            current_data = list(string_to_data(undecoded_str))



        elif int(user_choice) == 6:
            print("Displaying image...")

            if current_data == None:
                print("(no data)")
            else:
                console_gfx.display_image(current_data)

        elif int(user_choice) == 7:

            print("RLE representation: ", end="")
            if current_data == None:
                print("(no data)")

            else:
                uncoded = encode_rle(current_data)
                print(to_rle_string(list(uncoded)))


        elif int(user_choice) == 8:

            print("RLE hex values: ", end="")
            if current_data == None:
                print("(no data)")
            else:

                uncoded = encode_rle(current_data)
                print(to_hex_string(list(uncoded)))

        elif int(user_choice) == 9:

            print("Flat hex values: ", end="")
            if current_data == None:
                print("(no data)")
            else:
                print(to_hex_string(current_data))




# Press the green button in the gutter to run the script.
if __name__ == '__main__':
    main()

