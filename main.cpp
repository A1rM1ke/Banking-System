#include <iostream>
#include "application.h"

int main() {

    App::Init();

    std::cout << "\n--Welcome to the Banking System!--\n";
    std::cout << "--Current Version: " << App::Instance->getVersion() << "--\n" << std::endl;

    int input = -1;
    while(!App::Instance->AppShouldClose) {
        App::Instance->PrintPrompt();

        App::Instance->PrintOptions();

        App::Instance->GetInput(input);

        App::Instance->ProcessInput(input);
    }

    App::AppTerminate();
    return 0;
}