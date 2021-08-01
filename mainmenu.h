#ifndef MAINMENU_H
#define MAINMENU_H

#include "menuclass.h"
#include "commandclass.h"
#include <iostream>

class MainMenuClass : public MenuClass{
    private:

        CommandClass CommandOne = CommandClass("Login", [] () {
            std::cout << "Switching to Login Screen" << std::endl;
        });

        CommandClass CommandTwo = CommandClass("Test", [] () { return ;});

    public:
        MainMenuClass(App* _appptr) : MenuClass(_appptr) {
            prompt = "Main Menu";

            this->SetCommands( {CommandOne, CommandTwo} );
        }
};

#endif