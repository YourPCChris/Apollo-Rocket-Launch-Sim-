
#include "weather.h"
#include "raylib.h"
//Weather CPP

//----------------------Force Management--------------------------------
ForceManagement::ForceManagement()
{
    forces = (Vector3){0.0f,0.0f,0.0f};
}

void ForceManagement::addXForce(int newForce) { forces.x = forces.x + newForce; }
void ForceManagement::addYForce(int newForce) { forces.y = forces.y + newForce; }
void ForceManagement::addZForce(int newForce) { forces.y = forces.y + newForce; }
void ForceManagement::resetForces() { forces = (Vector3){0.0f, 0.0f, 0.0f}; }
int ForceManagement::getXForce() { return forces.x; }
int ForceManagement::getYForce() { return forces.y; }
int ForceManagement::getZForce() { return forces.z; }


//-----------------------Wind-------------------------------------------
Wind::Wind()
{
    speed = 0.5;
}

void Wind::setDirection(Direction newDirection) { direction = newDirection; }
void Wind::setSpeed(int newSpeed) { speed = newSpeed; }
int Wind::getSpeed() { return speed; }
Direction Wind::getDirection() { return direction; }


//-----------------------Gravity------------------------------------------
Gravity::Gravity(int newG) : g(newG) {};
void Gravity::setG(int newG) { g = newG; }
int Gravity::getG() { return g; }



