#ifndef PLANE_H
#define PLANE_H

class plane{
public:
    plane();
    plane(float a, int b, int c, int d, int e, float f, bool g, bool h)
    : cargo(a), requested_time(b), departure_time(c), fuel(d), people(e), priority(f), grandchild(g), arrival(h) {};
    friend bool operator<(const plane &p1, const plane &p2); //compares priorities
    friend bool operator <=(const plane &p1, const plane &p2);
    float cargo;
    int requested_time;
    int departure_time;
    int fuel;
    int people;
    float priority;
    bool grandchild;
    bool arrival;
};

#endif
