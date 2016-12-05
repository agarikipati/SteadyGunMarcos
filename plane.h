#ifndef PLANE_H
#define PLANE_H

#include <iostream>

class plane{
    friend bool operator<(const plane &p1, const plane &p2); //compares priorities
    friend bool operator <=(const plane &p1, const plane &p2);
    friend std::ostream& operator<< (std::ostream &out, const plane &p);
public:
    plane();
    plane(float a, int b, int c, int d, int e, float f, bool g, bool h)
    : cargo(a), requested_time(b), departure_time(c), fuel(d), people(e), priority(f), grandchild(g), arrival(h) {};

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
