#ifndef MENUCLASS_H
#define MENUCLASS_H

#include <vector>
#include "commandclass.h"
#include "application.h"

/*
**  This class is the base class for any of the Menu classes
**  It is built in a way such that when creating an inherited class instance
**  but storing in a MenuClass, all of the methods and member variables are accessible
*/

// MAKE SURE THE ENUM ORDER IS THE SAME AS THE
// INITIALIZATION ORDER OF THE MENUS IN APP CONSTRUCTOR
enum MENUS {
    MAIN_MENU,
    LOGIN_MENU
};

//Declaring App class for forward referencing
class App;

/****************
**  MenuClass  ** 
****************/

class MenuClass {

    /**************
    **  PRIVATE  **
    **************/

    private:

        //A vector that stores the commands for each menu as a CommandClass
        std::vector<CommandClass> commandsList;

    /****************
    **  PROTECTED  **
    ****************/

    protected:

        //A string to store the prompt at the top of the menu
        //I.e the name of the menu
        const char* prompt;

        //A pointer to the App class instance for the commands to reference
        App* appptr = nullptr;

        //Takes in a { } list of CommandClass instances
        //and stores in the commands vector
        //Only used by child classes
        void SetCommands(std::initializer_list<CommandClass> commands) {
            commandsList = commands;
        }

        //The constructor that sets the App pointer
        //Only called by child classes
        MenuClass(App* _appptr) : appptr(_appptr) {
        }

    /*************
    **  PUBLIC  **
    *************/

    public:
        //Run a command at an index
        void RunCommand(int indx) {
            //Run the requested command
            //Note: Subtract 1 from the index
            //since the commands are stored in an array and start from 0
            commandsList[indx - 1].Invoke();
        }

        //Returns the prompt
        const char* getPrompt() {
            return prompt;
        }

        //Prints all of the possible options (except exit)
        void printOptions() {
            //For all CommandClass objects in the commandList array
            for(long unsigned int i = 0; i < commandsList.size(); i++) {
                //Print the index and the name of the command
                std::cout << "\t" << i + 1 << ". " \
                << commandsList[i].getName() << "\n";
            }
        }

        //Returns the size of the commandsList
        int getOptionSize() {
            return commandsList.size();
        }

        App* getAppPtr() const {
            return appptr;
        }
};

#endif