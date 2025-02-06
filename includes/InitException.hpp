#include <iostream>

class InitException : public std::exception {
private:
    char * message;

public:
    InitException(char * msg) : message(msg) {}
    char * what () {
        return message;
    }
};