#ifndef MAINMENU_H
#define MAINMENU_H

#include "menuclass.h"
#include <iostream>

class MainMenuClass : public MenuClass{
    private:
        static void commandOne() {
            std::cout << "Passing to Login\n";
            //Change class
        }

    public:
        MainMenuClass() {
            prompt = "Main Menu";
            options = "\t1. Login\n";

            this->addCommand( (void (*)()) &commandOne);

            num_of_options = 1;
        }
};

#endif