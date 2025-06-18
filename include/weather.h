
enum Direction() { LEFT, RIGHT };
class Wind()
{
    int 
        speed;
    Direction direction;

    public:
        Wind();
        void setDirection(Direction newDir);
        void setSpeed(int newSpeed);
        int getSpeed();
        Direction getDirection();
};

class Gravity()
{
    int g;

    public: 
    Gravity() : g(10);
    void setG(int newG);
    int getG();

};
