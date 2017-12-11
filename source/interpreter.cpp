#include <iostream>
#include <string>
#include "mygame.h"

using namespace std;

Intepreter :: Intepreter() {
    printf("Instance created\n");
}

/*Command intepreter is a singleton.
Create single instance of Intepreter.
Can be called multiple times,
even though it is futile.*/
Intepreter& Intepreter :: getInstance() {
    static Intepreter instance;
    return instance;
}

void Intepreter :: intepretCmd(string playerInput) {
    
}