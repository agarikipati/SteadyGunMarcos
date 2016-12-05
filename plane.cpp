#include "plane.h"

plane::plane(){
    cargo = 0;
    requested_time = 0;
    departure_time = 0;
    fuel = 0;
    people = 0;
    priority = 0;
    grandchild = 0;
    arrival = 0;
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
