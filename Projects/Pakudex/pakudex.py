# by Jose Reynaldo on 16/3/24


from pakuri import Pakuri


class Pakudex:

    def __init__(self):
        self.pakuri_list = []

    def get_species_list(self):

        if len(self.pakuri_list) == 0:
            return None

        printout = []
        for species in self.pakuri_list:
            printout.append(species.get_species())

        return printout

    def get_stats(self, search_species: str):
        printout = []
        for species in self.pakuri_list:
            if species.get_species() == search_species:
                printout.append(species.level)
                printout.append(species.cp)
                printout.append(species.hp)
                return printout

        return None

    def sort_pakuri(self):
        sorting_list = []
        for species in self.pakuri_list:
            sorting_list.append(species.get_species())

        sorting_list.sort()
        new_pakuri_list = []

        for x in range(0, len(self.pakuri_list)):
            for species in self.pakuri_list:
                if sorting_list[x] == species.get_species():
                    new_pakuri_list.append(species)

        self.pakuri_list = new_pakuri_list

    def add_pakuri(self, species: str, level: int):

        # first checks if species already exists
        for itterator in self.pakuri_list:
            if itterator.get_species() == species:
                return False

        paki = Pakuri(species, level)
        self.pakuri_list.append(paki)

        return True

    def remove_pakuri(self, species: str):
        for itterator in self.pakuri_list:
            if itterator.get_species() == species:
                self.pakuri_list.remove(itterator)
                return True

        return False

    def evolve_species(self, species: str):
        for x in range(0, len(self.pakuri_list)):
            if self.pakuri_list[x].get_species() == species:
                new_level = self.pakuri_list[x].level * 2
                self.pakuri_list[x].level = new_level
                self.pakuri_list[x].set_attack(self.pakuri_list[x].get_attack() + 1)
                return True
        return False


# start of actual program under

# helper methods
def print_menu():
    print("\nPakudex Main Menu")
    print("-----------------")
    print("1. List Pakuri")
    print("2. Show Pakuri")
    print("3. Add Pakuri")
    print("4. Remove Pakuri")
    print("5. Evolve Pakuri")
    print("6. Sort Pakuri")
    print("7. Exit\n")


def check_menu_input():
    user_truth = True

    while user_truth:
        flag = False
        userChoice = input("What would you like to do? ")
        try:
            int(userChoice)

        except ValueError:
            flag = True

        if flag:
            print("Unrecognized menu selection!")

        elif int(userChoice) > 7 or int(userChoice) < 1:
            print("Invalid, please choose a number between 1 and 7")
        else:
            userChoice = int(userChoice)
            user_truth = False
            print()

        return userChoice


def main():
    counter = True
    print("Welcome to Pakudex: Tracker Extraordinaire!")

    puka = Pakudex()

    while counter:
        print_menu()
        user_choice = check_menu_input()

        match user_choice:
            case 1:
                pukari_list = puka.get_species_list()
                isEmpty = True
                # logic to dertime if emtpy
                if not pukari_list:
                    print("No Pakuri currently in the Pakudex!")
                    isEmpty = False
                    #actually print
                if isEmpty:
                    print("Pakuri in Pakudex:")
                    i = 0
                    # prints out pakuris
                    for capsule in pukari_list:
                        i += 1
                        print(str(i) + ". " + capsule)
            case 2:
                species_name = input("Enter the name of the species to display: ")
                pukari_list = puka.get_stats(species_name)

                # checks if it actually is there
                if pukari_list == None:
                    print("Error: No such Pakuri!")
                else:
                    print()
                    print("Species: " + species_name)
                    print("Level: " + str(pukari_list[0]))
                    print("CP: " + str(pukari_list[1]))
                    print("HP: " + str(pukari_list[2]))


            case 3:
                species = input("Species: ")
                list_o_species = puka.get_species_list()
                search_up_values = puka.get_stats(species)
                rest_of_program = True


                if not search_up_values == None:
                    print("Error: Pakudex already contains this species!")
                    # found to be duplicate
                    rest_of_program = False



                # if duplicate quit early
                while rest_of_program:
                    is_negative = True

                    level = 0

                    while is_negative:
                        level = input("Level: ")
                        flag = False
                        try:
                            int(level)

                        except ValueError:
                            flag = True
                        if flag:
                            print("Invalid Level!")
                        elif int(level) < 0:
                            print("Level cannot be negative")
                        else:
                            level = int(level)
                            is_negative = False
                    did_work = puka.add_pakuri(species, level)
                    if did_work:
                        print("Pakuri species " + species + "(level " + str(level) + ") added!")
                    else:
                        print("Error: Pakudex already contains this species!")
                    rest_of_program = False

            case 4:
                species = input("Enter the name of the Pakuri to remove: ")
                # checks the object for the logic
                is_there = puka.remove_pakuri(species)
                if is_there:
                    print("Pakuri " + species + " removed.")
                else:
                    print("Error: No such Pakuri!")

            case 5:
                species = input("Enter the name of the species to evolve: ")
                is_there = puka.evolve_species(species)
                # is_there will determine the logic that comes from class def
                if is_there:
                    print(species + " has evolved!")
                else:
                    print("Error: No such Pakuri!")


            case 6:
                puka.sort_pakuri()
                print("Pakuri have been sorted!")
            case 7:
                print("Thanks for using Pakudex! Bye!")
                counter = False



if __name__ == "__main__":
    main()