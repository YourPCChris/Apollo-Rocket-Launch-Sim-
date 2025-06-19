#pragma once
#include "raylib.h"

class Rocket
{
    Vector3 pos;
    float
        width,
        height,
        depth,
        dy,
        dx,
        dz;
    Color color;
    bool boosterOn;

    public:
    Rocket();
    void launch();
    void display();
    void update(int xForces, int yForces, int zForces);
    void pause();
    void resetPos();
    bool getBoosterOn();
};
