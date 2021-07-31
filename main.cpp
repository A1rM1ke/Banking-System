#include <iostream>
#include <nlohmann/json.hpp>

using json = nlohmann::json;

void printPrompt();
void printOptions();
void getInput(int& output, int range);
void processInput(int& input);
void terminateApp();

int main() {

    const char* version_num = "1.0.0";

    std::cout << "Welcome to the Banking System!\n";
    std::cout << "Current Version: " << version_num << "\n" << std::endl;

    int input = -1;
    while(true) {
        printPrompt();

        printOptions();

        getInput(input, 3);

        processInput(input);
    }
}

void printPrompt() {
    std::cout << "\t--Main Menu--\n";
}

void printOptions() {
    std::cout << \
    "\t 1. Login\n" \
    "\t 2. Create an Account\n" \
    "\t 3. About the System\n" \
    "\t 0. Exit" \
    << std::endl;
}

void getInput(int& output, int range) {
    int temp = -1;

    do {
        std::cout << "Pick an option: ";
        std::cin >> temp;
    } while(temp < 0 || range < temp);
    output = temp;
}

void processInput(int& input) {
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

void terminateApp() {
    std::cout << "Goodbye." << std::endl;
    exit(0);
}