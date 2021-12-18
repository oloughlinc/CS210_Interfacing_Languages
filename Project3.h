/* CS210 Project Three: Corner Grocer
 * Author: Craig O'Loughlin     Date: 12/10/2021
 *
 * C++ code which interfaces with Python code to interface with data stored in a text file representing grocery items and how many were purchased.
 * Functions:
 *      1. Call python code to display all grocery items along with purchase count from a .txt file
 *      2. Call python code to provide a purchase count for a single item. Output is displayed from c++ code.
 *      3. Call python code to create a frequency.dat file which mirrors the input .txt file. Call c++ code to display the data as histogram.
 */


#include "CS_Starter_CPP_Code.h" //including provided library to interface with python module

class Project3 { //begin class definition

    public:

        void ProgramHeader();
        bool MainMenu(); //display the main menu, wait for input, then act on the input. Return false only if quit is selected

    private:

        void MenuOptions(); //defines the menu option text
        char GetCharInput(); //get a single char input
        std::string GetLineInput(); //get the next line from input
        //call python funcs
        void DisplayAllItems(); //call python function to display grocery items
        void DisplayOneItem(); // call python function to display single grocery item
        void DisplayHistogram(); // call python function to write .dat file then display histogram using that data in c++
        void OpenDataFile(const std::string& file, std::ifstream& inFS); // open a data file using ifstream object
        void OutputHistogram(std::ifstream& inFS); // read a file and display as a histogram

};


