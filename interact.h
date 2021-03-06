#ifndef INTERACT_H
#define INTERACT_H

#include "plane.h"
#include "priority.h"
#include "airport.h"
#include <iostream>
#include <fstream>
#include <string>
#include <sstream>

class interact{
public:
    interact();
    void ProcessFile(std::ifstream& infile); //Handles input
private:
    int latest_time; // Keeps track of latest flight request
    priority_queue<plane> orders; // Keeps flight requests in order
    airport headless_horse; 
    void PrintStatistics(int time); 
    void PrintStatistics();
    void LoadPlanes();
    bool CheckInput(std::string &toCheck);
    void MakeLowercase(std::string &toConvert);
    bool ParseData(std::string &rawData);
};

#endif
