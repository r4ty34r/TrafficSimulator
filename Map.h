#pragma once 
#include "Road.h"
#include<iostream>

// map class is used to contain all other items 

class Map
{
	public:
		void initialize();
		Road getRoad(){return completeRoadObject;} // getter for the simulator class 
		void update(); // called on by simulator to change positions and lights 
	private:
		std::vector<Road> listOfRoads;		
		//Road completeRoadObject; // contains list of all road items
}; // end class definition 
