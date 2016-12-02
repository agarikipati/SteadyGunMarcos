#include "airport.h"

airport::Airport(){
     data.avg_takeoff_wait = 0;
     data.avg_land_wait = 0;
     data.crashes = 0;
     data.departing = 0;
     data.arriving = 0;
     data.people_landed_safely = 0;
     data.people_killed = 0;
     data.grandchildren_killed = 0;
     data.avg_grandchild_wait = 0;
     data.cargo_landed_safely = 0;
     data.destroyed_cargo = 0;
     data.time_processing_input = 0;
}

int airport::GetTime(){
    return curr_time;
}

stats* airport::GetData(){
    return &data;
}

/**
do something like this... 

while(curr_time <= final_time){
     RunTimeUnit()
}

**/

void airport::RunTillTime(int final_time){
    // TODO
}

/**
do something like ...

if( toAdd.requested_time > curr_time)
    RunTillTime(requested_time - 1)

AssignPriority(toAdd);
arrivals.Insert(toAdd);

**/

void airport::AddArrival(plane &toAdd){
    // TODO
}

/**
   do something like...

if (toAdd.requested_time > curr_time)
    RunTillTime(requested_time - 1)
AssignPriority(toAdd)
departures.Insert(toAdd);

**/

void airport::AddDeparture(plane &toAdd){
    // TODO
}

/**
do something like ...

while(!arrivals.IsEmpty() || !departures.IsEmpty()){
     RunTimeUnit();
}

**/
void airport::RunTillEmpty() {
    // TODO
}

/**
Function should do the following

Check the filling station to see if the plane is ready to go back into one of the priority queue.  
If so, load it and any others that are ready into their appropriate priority queue.

Should select two planes to depart and arrive on the two lanes.  Also should update the statistics

 **/
void airport::RunTimeUnit(){
    // TODO
}

/**
Should assing priority to the plane.
Here was our scheme

fuel.(1 / cargo_economic_value)

if plane has family member, subtract 1 from fuel
add the departure time to the fuel value to adjust for planes that have been in flight

**/
void AssignPriority(plane &toModify){
    // TODO
}
