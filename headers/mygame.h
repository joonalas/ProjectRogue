#ifndef INTEPRETER_HEADER
#define INTEPRETER_HEADER
#include <string>

/*
    CONSTANTS
+-------------------------------------------------------------------------------+
*/

const int TILE_WIDTH = 20;
const int TILE_HEIGHT = 20;

/*
    CLASSES
+-------------------------------------------------------------------------------+
*/

class Terrain {
    public:
    //All derived classes should have virtual or protected destructor.
    virtual ~Terrain() = 0;
    virtual void draw() = 0;
};

//dungeon rooms
class Room {
    private:
    Terrain** blueprint;
    //Room position in the floor
    int x;
    int y;
    //Room dimensions
    int w;
    int h;
    public:
    Room(int posX, int posY);
    ~Room();
    void drawRoom();
};

//dungeon floors
class Floor {
    private:
    Room** blueprint;
    //int blueprintLength;
    //floor dimensions
    int w;
    int h;
    //Number of rooms
    int roomCount;
    public:
    Floor();
    ~Floor();
    void renderFloor();
};

class BareGround: public Terrain {
    public:
    //Init
    BareGround(int x, int y);
    //Deallocate memory
    ~BareGround();
    //Render terrain tile
    void draw();

    private:
    //Tile position
    int x;
    int y;
};

#endif