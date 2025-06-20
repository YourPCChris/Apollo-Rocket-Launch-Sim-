#pragma once
#include "raylib.h"

class Rocket
{
    Vector3 pos;
    Vector3 force;
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
    void update(float xForces, float yForces, float zForces);
    void pause();
    void resetPos();
    bool getBoosterOn();
    Vector3 getForce();
    void minusForce(Vector3 newForce);
};
