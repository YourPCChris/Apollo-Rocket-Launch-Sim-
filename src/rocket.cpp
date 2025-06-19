
#include "rocket.h"

Rocket::Rocket()
{
    width = 10;
    height = 10;
    depth = 10;
    color = RED;
    dx = 0;
    dy = 0;
    pos = (Vector3){0.0f,height/2,0.0f};
    boosterOn = false;
}


void Rocket::launch()
{
    boosterOn = true;
    //Booster animation 
    //set dy
    dy = 1;
}

void Rocket::update(int xForces, int yForces, int zForces)
{
    pos.x += dx + xForces;
    pos.y += dy + yForces;
    pos.z += dz + zForces;
}

void Rocket::pause()
{
    boosterOn = false;
    dy = 0;
    dx = 0;
    dz = 0;
}

void Rocket::resetPos()
{
    pause();
    pos = (Vector3){0.0f,(float)height/2,0.0f};
}

void Rocket::display()
{
    DrawCube(pos, width, height, depth, color);

    //Draw Pyramid on top 
    Vector3 bottomLeft = {pos.x - width/2, pos.y + height/2, pos.z - width/2};
    Vector3 topLeft = {pos.x-width/2, pos.y+height/2, pos.z+width/2};
    Vector3 topRight = { pos.x+width/2, pos.y+height/2, pos.z-width/2};
    Vector3 bottomRight = { pos.x+width/2, pos.y+height/2, pos.z+width/2};
    Vector3 peak = {pos.x, pos.y+(height*2), pos.z};

    DrawTriangle3D(bottomLeft, topLeft, peak, color);
    DrawTriangle3D(topLeft, topRight, peak, color);
    DrawTriangle3D(topRight, bottomRight, peak, color);
    DrawTriangle3D(bottomRight, bottomLeft, peak, color);
}

bool Rocket::getBoosterOn() { return boosterOn;}

