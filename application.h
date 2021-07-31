#ifndef APPLICATION_H
#define APPLICATION_H

#include <iostream>

enum MENUS {
    MAIN_MENU,
    LOGIN_MENU
};

class App {
    private:
        const char* version = "1.0.0";
        MENUS current_menu;

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
        std::cout << "\t--Main Menu--\n";
    }

    //Prints the options for selection
    void PrintOptions() {
        std::cout << \
        "\t 1. Login\n" \
        "\t 2. Create an Account\n" \
        "\t 3. About the System\n" \
        "\t 0. Exit" \
        << std::endl;
    }

    //Reads input from cin
    void GetInput(int& output, int range) {
        int temp = -1;

        do {
            std::cout << "Pick an option: ";
            std::cin >> temp;
        } while(temp < 0 || range < temp);
        output = temp;
    }

    //Processes the input
    void ProcessInput(const int& input) {
        if(input == 0) {
            terminateApp();
        }

        switch(input) {
            case 1:
                std::cout << "\n\n Proceeding to the Login screen.\n";
                break;
            case 2:
                std::cout << "\n\n Proceeding to account creation screen.\n";
                break;
            case 3:
                std::cout << "\n\n Proceeding to the Information screen.\n";
                break;
        }
    }

    //Terminates the application
    void terminateApp() {
        std::cout << "Goodbye." << std::endl;
        exit(0);
    }

    //Constructor
    App() {
        //On start, the menu is main menu
        current_menu = MAIN_MENU;
    }
};

#endif