#include "interact.h"

/**
Takes in a stream for the input file as parameter.  Processes the input.
Should have branch that looks something like the following 

while !EOF
{
if(data)
   create plane object with appropriate data.  if not formatted properly throw error.
   should set plane priority element equivalent to the request_time parameter
   put plane object into the orders priority queue
   update latest_time if the requested time is greater than latest_time
if (W)
   request input from cin and ignore input
if(P)
   call LoadPlanes() function. 
   call PrintStatistics(latest_time)
}

LoadPlanes()
headless_horse.RunTillEmpty()
PrintStatistics()

**/

void interact::ProcessFile(std::ifstream& infile){
    //TODO
}

/**

Gets the data from the airport and prints the data in a clean format.
Should look something like ...

stats* our_stats = headless_horse.GetData()
print the statistics in a pretty way :))))

**/

void interact::PrintStatistics(){
    //TODO
}

/**
should look something like ...

headless_horse.RunTillTime(time)
PrintStatistics()
**/

void interact::PrintStatistics(int time) {
    //TODO
}


/**
pipe's the planes over to the airport
should look something like ...

while (!orders.IsEmpty()){

    if(plane is arrival){
        remove plane from queue
        headless_horse.AddArrival(the plane)
    }
    else{
        remove plane from queue
        headless_horse.AddDeparture(the plane)
    }

}

**/

void interact::LoadPlanes() {
    // TODO
}
