#ifndef AIRPORT_H
#define AIRPORT_H

struct stats{
    float avg_takeoff_wait;
    float avg_land_wait;
    int crashes;
    int departing;
    int arriving;
    int people_landed_safely;
    int people_killed;
    int grandchildren_killed;
    float avg_grandchild_wait;
    int cargo_landed_safely;
    int destroyed_cargo;
    float time_processing_input;
};

class airport{
public:
    airport();
    int GetTime();
    stats* GetData();
    void RunTillTime(int final_time);
    void AddArrival(plane &toAdd);
    void AddDeparture(plane &toAdd);
    void RunTillEmpty();
private:
    void RunTimeUnit();
    void AssignPriority(plane &toModify);
    int curr_time;
    stats data; 
    priority_queue<plane> arrivals;
    priority_queue<plane> departures;
    queue<plane> filling;
};

#endif
