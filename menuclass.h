#ifndef MENUCLASS_H
#define MENUCLASS_H

#include <vector>
#include "commandclass.h"
#include "application.h"

enum MENUS {
    MAIN_MENU,
    LOGIN_MENU
};

class App;

class MenuClass {
    private:

        std::vector<CommandClass> commandsList;

    protected:

        const char* prompt;
        const char* options;

        App* appptr = nullptr;

        void SetCommands(std::initializer_list<CommandClass> commands) {
            commandsList = commands;
        }

        MenuClass(App* _appptr) : appptr(_appptr) {
        }

    public:
        void RunCommand(int indx) {
            if(indx < 0 || indx > this->commandsList.size() - 1)
                throw("Error: Given Index is not in the range.");

            //Run the requested command
            commandsList[indx].Do();
        }

        const char* getPrompt() {
            return prompt;
        }

        void printOptions() {
            for(int i = 0; i < commandsList.size(); i++) {
                std::cout << "\t" << i + 1 << ". " \
                << commandsList[i].getName() << "\n";
            }
        }

        int getOptionSize() {
            return commandsList.size();
        }
};

#endif