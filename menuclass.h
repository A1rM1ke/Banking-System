#ifndef MENUCLASS_H
#define MENUCLASS_H

#include <vector>

class MenuClass {
    private:
        const char* prompt;
        const char* options;

        std::vector<void (*)()> commands;

    public:
        void RunCommand(int indx) {
            if(indx < 0 || indx > this->commands.size() - 1)
                throw("Error: Given Index is not in the range.");

            //Run the requested command
            commands[indx]();
        }
};

#endif