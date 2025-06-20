#include <vector>
#include <memory>
#include "raylib.h"

enum Direction { LEFT, RIGHT };
struct Sphere
{
    Vector3 center;
    int radius;
    Color color;
};

class Wind
{
    Vector3 force;
    int speed;
    std::vector<std::unique_ptr<Sphere>> balls;
    Direction direction;
    bool isOn;

    public:
        Wind();
        void update();
        void display();
        void setDirection(Direction newDir);
        void setSpeed(int newSpeed);
        int getSpeed();
        Vector3 getForce();
        Direction getDirection();
        bool getIsOn();
        void turnOn();
        void turnOff();
};

class Gravity
{
    int g;
    bool isOn;
    Vector3 force;

    public: 
    Gravity(int newG=10);
    void setG(int newG);
    Vector3 getForce();
    int getG();
    void turnOn();
    void turnOff();
};

class ForceManagement
{
    Vector3 forces;

    public:
    std::unique_ptr<Wind> wind;
    std::unique_ptr<Gravity> gravity;

    ForceManagement();
    void addXForce(int newForce);
    void addYForce(int newForce);
    void addZForce(int newForce);
    void resetForces();
    int getXForce();
    int getYForce();
    int getZForce();
    void update();
};
