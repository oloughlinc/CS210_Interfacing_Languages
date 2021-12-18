#include "Project3.h" //project3 class definition
#include <memory> // for make_unique

int main() {
    
    auto cornerGrocer = std::make_unique<Project3>(); // create new project3 object and reference with auto memory manage
    cornerGrocer->ProgramHeader();
    while (true) { //main loop
        if ( ! (cornerGrocer->MainMenu())) { //display program main menu
            return 0; // if mainmenu returns false meaning user quit
        }
    }
}