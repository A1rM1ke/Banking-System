#ifndef COMMANDCLASS_H
#define COMMANDCLASS_H

#include "application.h"
#include <functional>

class CommandClass {
    private:
        const char* name;
        std::function<void()> command;
    public:
        CommandClass(const char* new_name, void (*func)()) {
            name = new_name;
            command = std::function<void()>(func);
        }

        void Do() const {
            command();
        }

        const char* getName() const {
            return name;
        }
};

#endif