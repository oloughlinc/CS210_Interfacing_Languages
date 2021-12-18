#include "Project3.h" //header file which includes the class definition
#include <string>   // for c++ strings
#include <fstream> // for file io
#include <iomanip> //for text alignment

using namespace std;

//display the header text of the cornergrocer program
void Project3::ProgramHeader() {
    cout << "Corner Grocer Application" << "\n"
         << "SNHU CS210 21EW6" << "\n"
         << "Craig O'Loughlin" << endl;
    cout << endl;
}

//Displays a menu to the console using cout stream object
void Project3::MenuOptions() {

    //following text to output
    cout << "1: Produce a list of all items purchased in a given day along with the number of times each item was purchased." << "\n"
         << "2: Produce a number representing how many times a specific item was purchased in a given day." << "\n"
         << "3: Produce a text-based histogram listing all items purchased in a given day, along with a representation of the number of times each item was purchased." << "\n"
         << "4: Quit" << "\n"
         << "Enter your selection as a number 1, 2, 3, or 4" << endl;

}

//display the menu options, then get the next input to decide which menu option to perform
//returns false if quit is selected from options else returns true
bool Project3::MainMenu() {

    MenuOptions(); //call to display menu

    switch (GetCharInput()) { //get a single character input and use it to decide which branch to take

        case '1': //if input char is 1
            DisplayAllItems(); //call to display all grocery items and freq
            break; //end switch

        case '2': //if input char is 2
            DisplayOneItem(); //call to display just one grocery item and freq
            break; //end switch

        case '3': //if input char is 3
            DisplayHistogram(); //call to display all grocery items and freq as a histogram 
            break; //end switch

        case '4': //if input char is 4
            return false; //end program state

        default:  //if any other input
            cout << "That option is not supported." << endl; //error message to screen
            cout << endl;
            break; //end switch
    }
    return true; //continue program
}

//Get a single char input from user. If not a single character at input return '0'
char Project3::GetCharInput() {
    string inputLine; //string var to store user input line
    getline(cin, inputLine); //get an entire input line up to newline
    if (inputLine.size() == 1) { //if the line contained only one char
        return inputLine.at(0);  //return that one char
    } else {
        return '0'; //otherwise return a '0' which will default case in main loop
    }
}

//Get a single input line into a string variable with no restrictions
string Project3::GetLineInput() {
    string inputLine; // string var to store input
    getline(cin, inputLine); // get the next line from cin and store in var inputLine
    return inputLine;   // return the input
}

//call the python function to display all grocery items using wrapper code provided in Starter C++ Code
void Project3::DisplayAllItems() {
    CallProcedure("printWordFrequencies"); //CallProcedure defined in Starter Code included in header file
}

//call the python function to display one grocery item using wrapper code provided in Starter C++ Code
//prompt user for the grocery item to search for
//displays 0 if grocery item does not exist
void Project3::DisplayOneItem() {
    cout << "Enter the item to search for: "; // prompt to output
    string itemToGet = GetLineInput(); // get input line from user
    cout << endl; // format spacing
    int itemPurchaseCount = callIntFunc("getSingleItemFreq", itemToGet); // call to Python function: return int purchase count for item
    cout << itemToGet << " " << itemPurchaseCount << endl; //display: {item} {count}
    cout << endl; // format spacing
}

//display the grocery list as a histogram using data written to "Frequency.dat from Python code"
void Project3::DisplayHistogram() {

    cout << endl;
    CallProcedure("writeWordFrequencies"); // call the Python function to write grocery items + purchase count to Frequency.dat

    const string FREQUENCY_FILE = "Frequency.dat"; // define the file that C++ code will look for
    ifstream inFS; // create an input file stream object to read a file

    try { // exception handling block
        OpenDataFile(FREQUENCY_FILE, inFS); //open the specified file. Throw runtime_error if unsuccessful
        OutputHistogram(inFS); //output the file contents as histogram. Throw runtime_error if file not formatted properly

    } catch (runtime_error& error) { //catch a runtime_error
        cout << error.what() << endl; //display the error at console and continue
    }
    inFS.close(); // close the input file when finished
}

//opens a designated file using a designated input file stream object. throw runtime_error if file is not found
void Project3::OpenDataFile(const string& file, ifstream& inFS) {
    inFS.open(file); //open file
    if ( ! inFS.is_open()) { //check: if file was not opened successfully then:
        throw runtime_error("Error opening " + file); //throw error
    }
    cout << "C++ opened " << file << "." << endl;
}

//output histogram formatted data from a file that is already opened in the input stream object.
//file must be opened first using OpenDataFile()
void Project3::OutputHistogram(ifstream& inFS) {

    //expecting string int format. create two variables to hold the string and int for each line
    string groceryItem; 
    int count;

    cout << "C++ attempting to read opened file." << endl; 
    cout << endl; //format newline
    while ( ! inFS.eof()) { //while not at the end of the file do:

        inFS >> groceryItem >> count; // get the next string and int, which constitutes a line from the .dat file

        if (inFS.fail()) { // if there was a problem reading the string and int
            throw runtime_error("Error reading the input file. Expecting {word} {number} format."); //throw runtime_error
        }

        cout << setw(15) << left << groceryItem << " "; //display the groceryItem with 15char width and left aligned
        for (int i = 0; i < count; i++) { // for the number of times this item was purchased per the file
            cout << "*";                  // add an asterisk to the output
        }
        cout << endl; // new line at console output
        
    }
    cout << endl; //format newline
}
