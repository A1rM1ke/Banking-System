#ifndef APPLICATION_H
#define APPLICATION_H

#include <iostream>
#include <vector>
#include "menuclass.h"
#include "mainmenu.h"

class App {
    private:
        const char* version = "1.0.0";
        MenuClass* current_menu = nullptr;
        std::vector<MenuClass> menus;
    public:

/***************************
*     Basic Functions      *
***************************/

    //Returns the version of the system
    const char* getVersion() {
        return version;
    }

    //Prints the prompt
    void PrintPrompt() {
        std::cout << "\t--" << current_menu->getPrompt() << "--\n";
    }

    //Prints the options for selection
    void PrintOptions() {
        current_menu->printOptions();
        std::cout << "\t0. Exit" << std::endl;
    }

    //Reads input from cin
    void GetInput(int& output) {
        int temp = -1;

        do {
            std::cout << "Pick an option: ";
            std::cin >> temp;
        } while(temp < 0 || current_menu->getOptionSize() < temp);
        output = temp;
    }

    //Processes the input
    void ProcessInput(const int& input) {
        if(input == 0) {
            terminateApp();
        }

        current_menu->RunCommand(input - 1);
    }

    //Terminates the application
    void terminateApp() {
        std::cout << "Goodbye." << std::endl;
        exit(0);
    }
    
    //Working with menus
    void UpdateMenu(MENUS newMenuIndex) {
        if(newMenuIndex < 0 || newMenuIndex >= menus.size())
            throw("Error: Given menu index is out of bounds");
        current_menu = &(menus[newMenuIndex]);
    }

    //Constructor
    App() {
        menus = {MainMenuClass(this)};
        //On start, the menu is main menu
        current_menu = &(menus[MAIN_MENU]);
    }
};

#endif