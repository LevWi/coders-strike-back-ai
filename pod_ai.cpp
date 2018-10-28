#include <math.h>

typedef double precision_t;

enum {
    RADIUS_DRONE = 400,
    RADIUS_CHECKPOINT = 600
};

struct Vector2D {
    precision_t x = 0;
    precision_t y = 0;
};

struct Circle
{
    Vector2D position;
    virtual inline precision_t getRadius() = 0;

    Circle() {}
    Circle(precision_t x, precision_t y) : position{x, y} {}
    virtual ~Circle() {}

    bool isCrossing(Circle& crcl) {
        return distance(crcl) < (getRadius() + crcl.getRadius());
    }

    inline virtual precision_t distance(Circle& p) { //TODO Need optimize
        return sqrt(pow((position.x - p.position.x), 2) +
                    pow((position.y - p.position.y), 2));
    }
};

struct Checkpoint : Circle
{
    Checkpoint() {}
    Checkpoint(precision_t x, precision_t y) : Circle{x, y} {}

    virtual inline precision_t getRadius() override {
        return RADIUS_CHECKPOINT;
    }
};

struct Drone : Circle
{
    Vector2D speed;
    int angel;
    double mass;
    int thrust;
    size_t nextCheckpoint;

    virtual inline precision_t getRadius() override {
        return RADIUS_DRONE;
    }
};

int main(int argc, char *argv[])
{
    return 0;
}
