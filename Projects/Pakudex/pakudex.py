from pakuri import pakuri


class Pakudex:

    def __init__(self):
        self.pakuri_list = []

    def get_species_list(self):
        printout = []
        for species in self.pakuri_list:
            printout.append(species)

        return printout

    def get_stats(self, searc_species: str):
        printout = []
        for species in self.pakuri_list:
            if species == searc_species:
                printout.append(species.level)
                printout.append(species.cp)
                printout.append(species.hp)
                return print()

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

        paki = pakuri(species, level)
        self.pakuri_list.append(paki)

        return True

    def remove_pakuri(self, species: str):
        for itterator in self.pakuri_list:
            if itterator.get_species() == species:
                self.pakuri_list.remove(itterator)
                return True

        return False

    def evolve_species(self, species: str):
        for itterator in self.pakuri_list:
            if itterator.get_species() == species:
                currentPaku = itterator
                currentPaku.level(itterator.level *2)
                currentPaku.set_attack(itterator.get_attack() + 1)
                self.pakuri_list[itterator.get_index()] = currentPaku



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
    print("What would you like to do?")


def check_menu_input():
    user_truth = True

    while user_truth:
        flag = False
        userChoice = input()
        try:
            int(userChoice)

        except ValueError:
            flag = True

        if flag:
            print("This is not an integer, please try again")

        elif int(userChoice) > 7 or int(userChoice) < 1:
            print("Invalid, please choose a number between 1 and 7")
        else:
            userChoice = int(userChoice)
            user_truth = False

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
                if not pukari_list:
                    print("No Pakuri currently in the Pakudex!")
                    isEmpty = False
                if isEmpty:
                    for species in pukari_list:
                        print(species.get_index() + " " + species.get_species() + "\n")
















if __name__ == "__main__":
    main()