#include "application.h"

/***********************************
**  Static Member Initialization  **
***********************************/

const char* App::version = "1.0.0";

App* App::Instance = nullptr;

/******************
**  Constructor  **
******************/

App::App() {
    //This initializes the menus vector
    //NOTE: It is important to initialize the menus in the order of the ENUMS in menuclass.h
    //I.e if the order in enums is MAIN_MENU, LOGIN_MENU, ABOUT_MENU, etc
    //The menus vector needs to initialized in the same order
    // { MainMenuClass(this), LoginMenuClass(this), AboutMenuClass(this), etc }
    menus = { MainMenuClass(this) };

    //On start, set the current_menu to main menu
    current_menu = &(menus[MAIN_MENU]);
}

/*************
**  PUBLIC  **
*************/

void App::Init() {

    if(Instance != nullptr){
        std::cout << "Error: Trying to initialize multiple instances of an App class.\n";
        exit(1);
    }

    //Creates a new Instance of the App class in the heap
    //And stores it's pointer in App::Instance
    Instance = new App();
}

void App::AppTerminate() {
    //Frees the dynamically allocated memory of the App instance
    delete Instance;
    std::cout << "\n\t--Goodbye!--" << std::endl;
}

const char* App::getVersion() {
    //Returns the app version as a string literal
    return version;
}

void App::PrintPrompt() {
    //Prints the current_menu's prompt
    //in a "--Prompt--" format
    std::cout << "\t--" << current_menu->getPrompt() << "--\n";
}

void App::PrintOptions() {
    //Invokes the current_menu's printOptions method
    current_menu->printOptions();

    //Prints the last "exit" option
    std::cout << "\t0. Exit\n" << std::endl;
}

void App::GetInput(int& output) {
    //A temporary integer to store the input in
    int temp = -1;

    //Do while loop
    do {
        //Prints the input reading prompt
        std::cout << "Pick an option: ";
        //Reads and stores user input into temp
        std::cin >> temp;

    //If the temp integer is less than 0
    //or larger than the possible options, repeats the loop
    } while(temp < 0 || current_menu->getOptionSize() < temp);
    
    //Set the provided input reference to equal to temp
    output = temp;
}

void App::ProcessInput(const int& input) {
    //If the input is 0, set the termination boolean to true and return
    if(input == 0) {
        AppShouldClose = true;
        return;
    }

    //Run the current_menu's command at the given index
    current_menu->RunCommand(input);
}

void App::UpdateMenu(MENUS newMenuIndex) {
    //If the given index is not in the range of possible menus
    if(newMenuIndex < 0 || newMenuIndex >= menus.size())
        //Throw an error
        throw("Error: Given menu index is out of bounds");

    //Make the current_menu to point to the newly selected menu
    current_menu = &(menus[newMenuIndex]);
}