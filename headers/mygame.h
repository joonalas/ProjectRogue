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
    //All derived classes should have virtual or protected destructor.
    virtual ~Terrain() = 0;
    virtual void draw() = 0;
};

//dungeon floors
class Floor {
    private:
    Terrain** blueprint;
    int blueprintLength;
    //floor dimensions
    int x;
    int y;
    public:
    Floor();
    ~Floor();
};

class BareGround: public Terrain {
    public:
    BareGround();
    void draw();
};

#endif