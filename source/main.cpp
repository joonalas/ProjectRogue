#include <iostream>
#include <string>
#include "mygame.h"

using namespace std;

int main() {
    //Get command intepreter instance
    Intepreter& intepreter = Intepreter :: getInstance();
    
    //Main loop flag
    bool quit = false;
    
    //Main loop
    while(!quit) {
        //player input
        string input = "";
        
        //Prompt player
        printf("Type q to quit: ");
        cin>>input;
        
        //check input
        if(input == "q") {
            quit = true;
        }
    }
    
    return 0;
}