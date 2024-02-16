# Jose Reynaldo and Marie Klinizing
import stringdata
import time

def main():
    cont = stringdata.get_data() #pull data from stringdata.py
    checks=["not_here", "mzzzz","aaaaa"] #create list for checks

    for i in range(len(checks)): #iterates through check list
        start=time.time() #print out the info from the linear search

        print("Testing Linear Search for:", checks[i])
        index=linear_search(cont, checks[i])
        end=time.time()-start

        if index==-1:
            print(checks[i], "not found")
        else:
            print(checks[i], "found at", index)
        print("Linear Search Time:", end, "\n")


        start = time.time() #print out the checks for the binary search
        print("Testing Binary Search for:", checks[i])

        index = binary_search(cont, checks[i])
        end = time.time() - start


        if index == -1:
            print(checks[i], "not found")
        else:
            print(checks[i], "found at", index)
        print("Binary Search Time: ", end, "\n")

def linear_search(container, element) -> int:
    for i, val in enumerate(container): #checks each element
        if val==element:
            return i
    return -1

def binary_search(container, element) -> int:
    min=0 #define min, max, mid
    max=len(container)-1
    while min <= max:
        mid = min + (max - min) // 2
        if element<container[mid]: #if not equal to mid, redefine max or min
            max=mid-1
        elif element>container[mid]:
            min=mid+1
        else:
            return mid
    return -1

if __name__=="__main__":
    main() #call main