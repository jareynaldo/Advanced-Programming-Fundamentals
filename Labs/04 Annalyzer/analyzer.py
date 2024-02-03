# Jose Reynaldo and Marie Klinzing

import stringdata
import time


def main():
    workingSet = stringdata.get_data()


    startTime = time.time()
    searchOutcome = binary_search(workingSet,"not_here")
    endTime = time.time()
    printSearches("Binary", "not_here", endTime, startTime)
    lookingForTerm("not_here", searchOutcome)


    startTime = time.time()
    searchOutcome = linear_search(workingSet, "not_here")
    endTime = time.time()
    printSearches("Linear", "not_here", endTime, startTime)
    lookingForTerm("not_here", searchOutcome)

    startTime = time.time()
    searchOutcome = binary_search(workingSet,"mzzzz")
    endTime = time.time()
    printSearches("Binary", "mzzzz", endTime, startTime)
    lookingForTerm("mzzzz", searchOutcome)


    startTime = time.time()
    searchOutcome = linear_search(workingSet, "mzzzz")
    endTime = time.time()
    printSearches("Linear", "mzzzz", endTime, startTime)
    lookingForTerm("mzzzz", searchOutcome)

    startTime = time.time()
    searchOutcome = binary_search(workingSet, "aaaaa")
    endTime = time.time()
    printSearches("Binary", "aaaaa", endTime, startTime)
    lookingForTerm("aaaaa", searchOutcome)

    startTime = time.time()
    searchOutcome = linear_search(workingSet, "aaaaa")
    endTime = time.time()
    printSearches("Linear", "aaaaa", endTime, startTime)
    lookingForTerm("aaaaa", searchOutcome)








def lookingForTerm(term, result):
    if result == -1:
        print(term + " Not found")
    else:
        print(term + " was found in spot " + str(result))
    print()

def printSearches(searchType, term, endTime, startTime):
    print(searchType + " search for '" + term + "' took " + str(endTime - startTime) + " seconds")

def binary_search(container, element):
    maxValue = len(container) - 1
    minValue = 0

    while minValue <= maxValue:
        midIndex = minValue + (maxValue - minValue) // 2  # Use integer division to ensure midIndex is an integer

        if container[midIndex] == element:
            return midIndex
        elif container[midIndex] < element:
            minValue = midIndex + 1
        else:
            maxValue = midIndex - 1

    return -1


def linear_search(container, element):
    for i in range(len(container)):
        if(container[i] == element):
            return i

    return -1;

if __name__ == "__main__":
    main()