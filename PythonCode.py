import re
import string

from collections import Counter  # For the word count, this dict subclass will also 'sort' itself by most common


def printsomething():
    print("Hello from python!")

def PrintMe(v):
    print("You sent me: " + v)
    return 100

def SquareValue(v):
    return v * v

# open the designated text file and read all lines into a dictionary, counting the occurences of each word in the file
# as the purchase amount
def createDictWordFrequencies() -> Counter:

    wordCountDict = Counter()  # create a new counter type dictionary
    filename = "CS210_Project_Three_Input_File.txt"

    try:
        # open the input file read-only as groceryFile. with block automatically closes the file afterwards.
        with open(filename, 'r') as groceryFile:
            print("Python opened " + filename + ".")
            groceryItems = groceryFile.readlines()  # read all lines into a list groceryItems
            print("Python read contents of " + filename + ".")
            for item in groceryItems:  # for each grocery item
                item = item.strip()  # remove the trailing newline
                wordCountDict[item] += 1  # adding to dictionary with a value of one if does not exist yet. If word already exists increment by one.

    except IOError:
        print("Error opening " + filename + ". Please check that the file exists in the same directory as main.exe.")
        
    print() # format newline
    return wordCountDict  # return the dictionary word count

# create the word count dictionary and get a single value at key 'item'
def getSingleItemFreq(item: string) -> int:
    item = item.capitalize() # if the user enters in all lowercase, still return the capitalized key item
    return createDictWordFrequencies()[item] #  returns zero instead of key error due to Counter() for undefined item

# create the word count dictionary and display all the values from most to least common
def printWordFrequencies():
    print() # format newline
    for item, count in createDictWordFrequencies().most_common(): # for each item and its count in the dictionary
        print(f'{item:<15} {count}') # output the item and its count. item is left justified 15 spaces
    print() # format newline

# create the word count dictionary and write the word count to "Frequency.dat"
def writeWordFrequencies(filename="Frequency.dat"): 
    groceryList = createDictWordFrequencies().most_common()  # create the word count dict and assign to groceryList
    try:
        with open(filename, 'w') as outputFile: # open the file in write mode as outputFile

            # for each grocery item and its count, along with a running count of the item 
            # enumerate returns a range of the number of keys in groceryList (itemNum)
            # groceryList iterable returns a key-value tuple pair of each grocery item and the purchase count (item, count)
            for itemNum, (item, count) in enumerate(groceryList): 
                if itemNum == len(groceryList) - 1:        # if last item 
                    outputFile.write(f'{item} {count}')    # do not add a newline
                else:                                      # else
                    outputFile.write(f'{item} {count}\n')  # add a newline after the item
    except IOError:
        print("Error writing file " + filename + ".")
    
    print("Python wrote file " + filename + ".")


#brief test script
if __name__ == "__main__":
    printWordFrequencies()
    writeWordFrequencies()
