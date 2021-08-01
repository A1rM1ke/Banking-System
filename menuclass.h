#ifndef MENUCLASS_H
#define MENUCLASS_H

#include <vector>

enum MENUS {
    MAIN_MENU,
    LOGIN_MENU
};

class MenuClass {
    private:

        std::vector<void (*)()> commands;

    protected:

        const char* prompt;
        const char* options;
        unsigned int num_of_options;

        void addCommand(void (*function)()) {
            commands.push_back(function);
        }

    public:
        void RunCommand(int indx) {
            if(indx < 0 || indx > this->commands.size() - 1)
                throw("Error: Given Index is not in the range.");

            //Run the requested command
            commands[indx]();
        }

        const char* getPrompt() {
            return prompt;
        }

        const char* getOptions() {
            return options;
        }

        int getOptionSize() {
            return num_of_options;
        }
};

#endif