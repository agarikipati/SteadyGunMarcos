#include "plane.h"

plane::plane(){
    int cargo = 0;
    int requested_time = 0;
    int departure_time = 0;
    int fuel = 0;
    int people = 0;
    float priority = 0;
    bool grandchild = 0;
    bool arrival = 0;
}

bool operator< (const plane &p1, const plane &p2){
    return p1.priority < p2.priority;
}

bool operator <=(const plane &p1, const plane &p2){
    return p1.priority <= p2.priority;
}

std::ostream& operator<< (std::ostream &out, const plane &p){
    out << p.priority;
    return out;
}
