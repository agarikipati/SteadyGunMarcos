#ifndef PLANE_H
#define PLANE_H

class plane{
public:
    plane();
    // plane(int a, int b, int c, int d, float e, bool f, bool g) : cargo(a), requested_time(b), fuel(c), people(d), priority(e), grandchild(f), arrival(g) {};
    bool operator<(const plane &p1, const plane &p2); //compares priorities
    bool operator>(const plane &p1, const plane &p2); //compares priorities
    int cargo;
    int requested_time;
    int departure_time;
    int fuel;
    int people;
    float priority;
    bool grandchild;
    bool arrival;
};

#endif
