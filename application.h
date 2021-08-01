#ifndef APPLICATION_H
#define APPLICATION_H

#include <iostream>
#include <vector>
#include "menuclass.h"
#include "mainmenu.h"

/*
**  The Class of the Application that will be
**  generalizing the functions.
*/
class App {
    
    /**************
    **  PRIVATE  **
    **************/

    private:
        //The version of the application
        const char* version = "1.0.0";
        
        //A pointer to a MenuClass that stores the currently
        //Active Menu
        MenuClass* current_menu = nullptr;

        //A vector that stores all of the menus
        std::vector<MenuClass> menus;
    
    
    /*************
    **  PUBLIC  **
    *************/

    public:
    //Returns the version of the system
    const char* getVersion() {
        return version;
    }

    //Prints the prompt of the current menu
    void PrintPrompt() {
        std::cout << "\t--" << current_menu->getPrompt() << "--\n";
    }

    //Prints the options of the current menu for selection 
    void PrintOptions() {
        //Invokes the MenuClass's printOptions method
        current_menu->printOptions();
        //Prints the last "exit" option
        std::cout << "\t0. Exit" << std::endl;
    }

    //Reads input from cin
    void GetInput(int& output) {
        //A temporary integer to store the input in
        int temp = -1;

        //Do while loop
        do {
            //Print the reading prompt
            std::cout << "Pick an option: ";
            //Read and store user input into temp
            std::cin >> temp;

        //If the provided input is less than 0
        // or larger than the possible options, repeat
        } while(temp < 0 || current_menu->getOptionSize() < temp);
        
        //Set the global input to equal to temp
        output = temp;
    }

    //Processes the given input
    void ProcessInput(const int& input) {
        //If the input is 0, exit the application using the global method
        if(input == 0) {
            terminateApp();
        }

        //Run the current menu's command at the index
        //NOTE: The commands are stored in an array,
        //So for example command "1" is at index 0
        //Therefore, we subtract 1 from the input
        //Before Providing the index
        current_menu->RunCommand(input - 1);
    }

    //Terminates the application
    void terminateApp() {
        //Prints goodbye and quits the process with exit code 0
        std::cout << "Goodbye." << std::endl;
        exit(0);
    }
    
    //Updating the current menu
    void UpdateMenu(MENUS newMenuIndex) { //MENUS is an enum

        //If the given index is not in the range of menus
        if(newMenuIndex < 0 || newMenuIndex >= menus.size())
            //Throw an error
            throw("Error: Given menu index is out of bounds");
        
        //Make the current menu to point to the newly selected menu
        current_menu = &(menus[newMenuIndex]);
    }

    /******************
    **  Constructor  **
    ******************/

    App() {
        //This initializes the menus vector
        //NOTE: It is important to initialize the menus in the order of the ENUMS in menuclass.h
        //I.e if the order in enums is MAIN_MENU, LOGIN_MENU, ABOUT_MENU, etc
        //The menus vector needs to initialized in the same order
        // { MainMenuClass(this), LoginMenuClass(this), AboutMenuClass(this), etc }
        //NOTE #2: Always pass this in the Menu Constructors
        //As they reference the App class
        menus = { MainMenuClass(this) };

        //On start, set the current_menu to main menu
        current_menu = &(menus[MAIN_MENU]);
    }
};

#endif