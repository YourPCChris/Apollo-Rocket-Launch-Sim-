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
        dx;
    Color color;

    public:
    Rocket();
    void launch();
    void display();
    void update();
};
