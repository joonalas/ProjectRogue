#ifndef INTEPRETER_HEADER
#define INTEPRETER_HEADER

#include <iostream>
#include <time.h>
#include <stdlib.h>

using namespace std;

/*
    CONSTANTS
+-------------------------------------------------------------------------------+
*/

const int TILE_WIDTH = 32;
const int TILE_HEIGHT = 32;

const int FLOOR_WIDTH = 1200;
const int FLOOR_HEIGHT = 960;

enum TERRAIN_SPRITES {
    TERRAIN_BAREGROUND,
    TERRAIN_WALL
};

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
    Room(int posX, int posY, int width, int height);
    ~Room();
    void drawRoom();
    int getWidth();
    int getHeight();
};

//dungeon floors
class Floor {
    private:
    Room** blueprint;
    //Number of rooms
    int roomCount;
    //floor dimensions
    int w;
    int h;
    public:
    Floor(int w, int h);
    ~Floor();
    void renderFloor();
};

//Terrain tiles

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

class Wall: public Terrain {
    public:
    //Init
    Wall(int x, int y);
    //Deallocate memory
    ~Wall();
    //Render terrain tile
    void draw();

    private:
    //tile position
    int x;
    int y;
};

#endif