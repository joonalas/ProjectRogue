#ifndef INTEPRETER_HEADER
#define INTEPRETER_HEADER
#include <string>

//Command intepreter
class Intepreter {
    private:
    //Hide constructor
    Intepreter();
    public:
    //Use to create and get the single instance
    static Intepreter& getInstance();
    //Intepret player input
    void intepretCmd(std::string);
};

class Terrain {
    public:
    virtual void draw() = 0;
};

//dungeon floors
class Floor {
    private:
    Terrain** blueprint;
    //floor dimensions
    int x;
    int y;
    public:
    Floor();
    void setDimensionX(int);
    void setDimensionY(int);
    int getDimensionX();
    int getDimensionY();
};

class BareGround: public Terrain {
    public:
    void draw();
};

#endif