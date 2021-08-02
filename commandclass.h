#ifndef COMMANDCLASS_H
#define COMMANDCLASS_H

#include "application.h"
#include <functional>

/*
**  Command Class is the container
**  for the commands that each menu has
*/

class CommandClass {

    /**************
    **  PRIVATE  **
    **************/
    
    private:
        //Name of the command
        const char* name;
        
        //The function stored in a function container
        std::function<void()> command;

    /*************
    **  PUBLIC  **
    *************/
   
    public:
        //Constructor
        CommandClass(const char* new_name, void (*func)()) {
            name = new_name;
            command = std::function<void()>(func);
        }

        //Invoker of the command
        void Invoke() const {
            command();
        }

        //Returns the name of the command
        const char* getName() const {
            return name;
        }
};

#endif