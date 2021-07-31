#include <iostream>
#include "application.h"

App application;

int main() {

    std::cout << "Welcome to the Banking System!\n";
    std::cout << "Current Version: " << application.getVersion() << "\n" << std::endl;

    int input = -1;
    while(true) {
        application.PrintPrompt();

        application.PrintOptions();

        application.GetInput(input, 3);

        application.ProcessInput(input);
    }
}