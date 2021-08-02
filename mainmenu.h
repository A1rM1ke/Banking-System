#ifndef MAINMENU_H
#define MAINMENU_H

#include "menuclass.h"
#include "commandclass.h"
#include <iostream>

/*
**  The MainMenu Class handles the main menu
**  where the user is entered when starting the application
**
**  Options:
**      1. Login
**      2. Create an Account
**      3. About Page
*/

class MainMenuClass : public MenuClass{

    /**************
    **  PRIVATE  **
    **************/

    private:

        /*
        **  All CommandClass objects take in the name of the command
        **  and the command itself as a lambda function
        */

        //Command #1: Login
        CommandClass CommandOne = CommandClass("Login", [] () {
            std::cout << "\nSwitching to Login Screen\n" << std::endl;
        });

        //Command #2: Create an Account
        CommandClass CommandTwo = CommandClass("Create an Account", [] () {
            std::cout << "\nSwitching to Create Account Screen\n" << std::endl;
        });

        //To-do: Add Command #3: About Page
        CommandClass CommandThree = CommandClass("About", [] () {
            std::cout << "\nSwitching to About Screen\n" << std::endl;
        });

    /*************
    **  PUBLIC  **
    *************/

    public:

        //Constructor
        MainMenuClass(App* _appptr) : MenuClass(_appptr) {
            prompt = "Main Menu";

            //Sets the commands with the above created ones
            this->SetCommands( {CommandOne, CommandTwo, CommandThree} );
        }
};

#endif