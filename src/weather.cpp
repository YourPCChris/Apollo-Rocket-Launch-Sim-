
#include <iostream>
#include "weather.h"
#include "raylib.h"
//Weather CPP

//----------------------Force Management--------------------------------
ForceManagement::ForceManagement()
{
    forces = (Vector3){0.0f,0.0f,0.0f};
    wind = std::make_unique<Wind>();
    gravity = std::make_unique<Gravity>();
}

Vector3 addVector3(Vector3 vecOne, Vector3 vecTwo)
{
    Vector3 tempVec = Vector3 { (float)vecOne.x + vecTwo.x, (float)vecOne.y + vecTwo.y, (float)vecOne.z + vecTwo.z };
    return tempVec;
}

void ForceManagement::update() 
{
    if (wind->getIsOn()) {
        forces = addVector3(forces, wind->getForce()); 
        wind->turnOff();
    }
    if (gravity->getIsOn()) {
        forces = addVector3(forces, gravity->getForce());
        gravity->turnOff();
    }
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
    force = Vector3 { 0.0f, 0.0f, 0.0f };
    speed = 10;
    isOn = false;
}

void Wind::display(){}

void Wind::setDirection(Direction newDirection) { direction = newDirection; }
Vector3 Wind::getForce() { return force; }
void Wind::setSpeed(int newSpeed) { speed = newSpeed; }
int Wind::getSpeed() { return speed; }
Direction Wind::getDirection() { return direction; }
bool Wind::getIsOn() { return isOn; }
void Wind::turnOn() 
{
    isOn = true; 
    force.x = speed;
}
void Wind::turnOff() 
{
    isOn = false; 
    force = (Vector3){0.0f, 0.0f, 0.0f};
}

//-----------------------Gravity------------------------------------------
Gravity::Gravity(int newG) : g(newG), force((Vector3){0.0f, 0.0f, 0.0f}){};
void Gravity::setG(int newG) { g = newG; }
int Gravity::getG() { return g; }
void Gravity::turnOn() { isOn = true; }
void Gravity::turnOff() { isOn = false; }
Vector3 Gravity::getForce() { return force; }
bool Gravity::getIsOn() { return isOn; }



