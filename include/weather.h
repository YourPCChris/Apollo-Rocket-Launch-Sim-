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
    int speed;
    std::vector<std::unique_ptr<Sphere>> balls;
    Direction direction;

    public:
        Wind();
        void setDirection(Direction newDir);
        void setSpeed(int newSpeed);
        int getSpeed();
        Direction getDirection();
};

class Gravity
{
    int g;

    public: 
    Gravity(int newG=10);
    void setG(int newG);
    int getG();

};

class ForceManagement
{
    Vector3 forces;

    public:
    ForceManagement();
    void addXForce(int newForce);
    void addYForce(int newForce);
    void addZForce(int newForce);
    void resetForces();
    int getXForce();
    int getYForce();
    int getZForce();
};
