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
        static const char* version;
        
        //A pointer to a MenuClass that stores the currently Active Menu
        MenuClass* current_menu = nullptr;

        //A vector that stores all of the menus
        std::vector<MenuClass> menus;
    
        //Constructor
        //Only used by the Init method 
        //Innaccessible outside of the class scope
        App();
    
    /*************
    **  PUBLIC  **
    *************/

    public:

        //Static variable that stores a pointer to the
        //active instance of the App class
        static App* Instance;

        //A boolean that stores whether the app is ordered to close
        bool AppShouldClose = false;

        //A public static method that initializes the application
        //Always call it at the start of the main function
        static void Init();

        //A static void that needs to be called before the return of the main function
        //It frees the allocated memory in the heap
        static void AppTerminate();

        //A static method that returns the version of the system
        static const char* getVersion();
        
        //Prints the prompt of the current menu
        void PrintPrompt();

        //Prints the options of the current menu for selection 
        void PrintOptions();

        //Reads input from cin
        void GetInput(int&);

        //Processes the given input
        void ProcessInput(const int&);
        
        //Updating the current menu
        void UpdateMenu(MENUS);

    
};

#endif