#include "interact.h"

#define wait "w"
#define printStats "p"
#define data 'd'
#define comma ','
#define departure 'd'
#define arrival_mark 'a'
#define grandkidz 'y'
#define noGrandkidz 'n'

//boolean function that checks if the input is a number
bool isPositiveFloat(std::string& c)
{ 
  for(int i=0; i<c.length(); i++)
  {
    int numOfDecimals = 0;
    if((c[i] < '0' || c[i] > '9'|| c[i] != '.'))
    {
      return false;
    }
    if(c[i]== '.')
    {
      numOfDecimals++;
      if(numOfDecimals > 1)
      {
        return false;
      }
    }

  }
  return true;
}

//checks if positive integer
bool isPositiveInt(std::string& c)
{
  for(int i=0; i<c.length(); i++)
  {
    if((c[i] < '0' || c[i] > '9'))
    {
      return false;
    }
  }
  return true;

}

/**
Takes in a stream for the input file as parameter.  Processes the input.
Should have branch that looks something like the following 

get line kinda thing store the shit in variables
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
    std::string rawInput;
    int curr_line = 1;
    while (infile.good())
    {
	getline(infile, rawInput);
	MakeLowercase(rawInput); //normalize the std::string to lowercase

	if(rawInput == wait)
	{
	    std::cout << "Press Enter key to continue..." << std::endl;
	    std::string doNothing;
	    std::cin >> doNothing;
	}
	else if(rawInput == printStats){
	    //FIXME headless_horse.LoadPlanes(); //Pass the planes onto the airport
	    PrintStatistics(latest_time);
	}
	else if(rawInput[0] == data)
	{
	    if(!ParseData(rawInput)){
		std::cout << "Please see error on line " << curr_line << std::endl;
	    }
	}
	else 
	{
	    //WILL THIS SAY THIS IF ITS AN EMPTY LINE?
	    //Maybe make an else if(rawInput=="\n") or something
	    std::cout << "Error on line " << curr_line << std::endl;
	    std::cout<< "Invalid input fam" << std::endl; 
      }
	curr_line++;
    }
}

/**

Gets the data from the airport and prints the data in a clean format.
Should look something like ...

stats* our_stats = headless_horse.GetData()
print the statistics in a pretty way :))))

**/

void interact::PrintStatistics(){
  stats* our_stats = headless_horse.GetData();
  std::cout<<"Avg Takeoff wait time:               "<< our_stats->avg_takeoff_wait <<std::endl;
  std::cout<<"Avg Landing wait time:               "<< our_stats->avg_land_wait<<std::endl;
  std::cout<<"Number of crashes:                   "<< our_stats->crashes <<std::endl; 
  std::cout<<"Number of departures:                "<< our_stats->departing<<std::endl;
  std::cout<<"Number of arrivals:                  "<< our_stats->arriving<<std::endl;
  std::cout<<"Number of people safely landed:      "<< our_stats->people_landed_safely<<std::endl;
  std::cout<<"Number of people killed  RIP:        "<< our_stats->people_killed<<std::endl;
  std::cout<<"Number of grandchildren killed. RIP: "<< our_stats->grandchildren_killed<<std::endl;
  std::cout<<"Avg grandchild wait time:            "<< our_stats->avg_grandchild_wait<<std::endl;
  std::cout<<"Value of cargo landed safely:        "<< our_stats->cargo_landed_safely<<std::endl;
  std::cout<<"Value of destroyed cargo:            "<< our_stats->destroyed_cargo<<std::endl;
  std::cout<<"Time processing input:               "<< our_stats->time_processing_input<<std::endl;
  std::cout<<""<<std::endl;

}

void interact::PrintStatistics(int time) {
    headless_horse.RunTillTime(time);
    PrintStatistics();
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
    while(!orders.IsEmpty()){
	plane toPipe = orders.GetNext();
	if (toPipe.arrival){
	    headless_horse.AddArrival(toPipe);
	}
	else{
	    headless_horse.AddDeparture(toPipe);
	}
    }
}

bool interact::CheckInput(std::string &toCheck){
    bool is_valid = false;
        if(!isPositiveInt(planeInputs[1])) //time >=0
        {
          std::cout<<"Time parameter invalid \n";
        }
        else if(planeInputs[2] != departure || planeInputs[2] != arrival_mark)// a,d for action only
        {
          std::cout<<"Action Parameter invalid"<<std::endl;
        }
        else if(!isPositiveInt(planeInputs[3])) //fuel >=0
        {
          std::cout<<"Fuel parameter invalid"<<std::endl;
        }
        else if(!isPositiveInt(planeInputs[4])) //ppl >=0
        {
          std::cout<<"People parameter invalid"<<std::endl;
        }
        else if(!isPositiveFloat(planeInputs[5]))//cargo >=0.0
        {
          std::cout<<"Cargo parameter invalid \n";
        }
        else if(planeInputs[6] != grandkidz|| planeInputs[6] != noGrandkidz)// y,n for grandchildren only
        {
          std::cout<<"Special Parameter invalid"<<std::endl;
        }
	else{
	    is_valid = true;
	}
	return is_valid;
}

void MakeLowercase(std::string &toConvert){
    for(int i = 0; i < toConvert.length(); i++){
	toConvert[x] = tolower(toConvert[x]); //makes command case insensitive
    }
}

bool interact::ParseData(std::string &rawData){
    istringstream ss(rawData); //streams my inputs
    std::string processedInput; //processed input variable
    std::string planeInputs[7]; //do I need to make my own string class?
    x=0;
    while(getline(ss, processedInput, comma)) //parses the input where the commas are.
    {
	if(x<7)
	{
	    planeInputs[x]=processedInput;
	}
	x++;
    }
    //these statements will check for errors in the input
    if(x != 6){ // if there arent exactly 7 inputs this line isnt correct
	std::cout<<"Incorrect number of inputs fam"<<std::endl;
	return false;
    }
    else if(!CheckInput(planeInputs)){
	std::cout << "Please modify your file" << std::endl;
	return false;
    }
    else
    {
	bool arrivingPlane = (planeInputs[2] == arrival_mark);
	bool grandChildOnPlane = (planeInputs[6] == grandkidz);
	if(planeInputs[1] > latest_time)
	{
	    latest_time= planeInputs[1];
	}
	/*FIXME
	//the plane class says it goes cargo, requested time, fuel, ppl, priority= requested time, grandchildren, arrival
	airplane = new plane(planeInputs[5], planeInputs[1], 0, planeInputs[3],planeInputs[4], 
			     planeInputs[1],grandChildOnPlane, arrivingPlane);
	orders.Insert(airplane);
	*/
	return true;
    }
}
