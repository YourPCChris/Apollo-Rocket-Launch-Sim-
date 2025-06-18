
#include "rocket.h"

Rocket::Rocket()
{
    pos = (Vector3){0.0f,0.0f,0.0f};
    width = 10;
    height = 10;
    depth = 10;
    color = RED;
    dx = 0;
    dy = 0;
}


void Rocket::launch()
{
    //Booster animation 
    //set dy
    dy = 1;
}

void Rocket::update()
{
    pos.x += dx;
    pos.y += dy;
    pos.z += dx;
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


